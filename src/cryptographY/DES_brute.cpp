#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-bmi -bmi2 -popcnt -abm -lzcnt -tbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm")
#pragma G++ optimize(3)
#pragma G++ optimize("Ofast")
#pragma G++ optimize("inline")
#pragma G++ optimize("-bmi -bmi2 -popcnt -abm -lzcnt -tbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm")
#include <atomic>
#include <bitset>
#include <chrono>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <openssl/des.h>
#include <string>
#include <thread>
#include <vector>

using namespace std;
#define endl '\n'
void encrypt(unsigned char* in, unsigned char* out, unsigned char* key) {
    DES_cblock* pin = (DES_cblock*)in;
    DES_cblock* pout = (DES_cblock*)out;
    DES_key_schedule ks;

    DES_set_key((DES_cblock*)key, &ks);
    DES_ecb_encrypt(pin, pout, &ks, DES_ENCRYPT);
}

void decrypt(unsigned char* in, unsigned char* out, unsigned char* key) {
    DES_cblock* pin = (DES_cblock*)in;
    DES_cblock* pout = (DES_cblock*)out;
    DES_key_schedule ks;

    DES_set_key((DES_cblock*)key, &ks);
    DES_ecb_encrypt(pin, pout, &ks, DES_DECRYPT);
}



std::mutex mtx;
std::atomic<bool> found{ false };
std::atomic<unsigned long long> cnt{ 0 };
// E01FE01FF10EF10E

template <typename T>
struct atomwrapper
{
    std::atomic<T> _a;

    atomwrapper() : _a(0) {}

    atomwrapper(const std::atomic<T>& a) : _a(a.load()) {}

    atomwrapper(const atomwrapper& other) : _a(other._a.load()) {}

    atomwrapper& operator=(const atomwrapper& other)
    {
        _a.store(other._a.load());
        return *this;
    }
};


constexpr unsigned long long dapow(unsigned long long a, unsigned long long b) {
    long long ans = 1;
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            ans = ans * a;
    return ans;
}
constexpr unsigned long long full_process = dapow(16ll, 8ll);
std::mutex output_lock;
int now[8] = {0};
constexpr uint64_t every_step = full_process / 100;
std::atomic_bool flag{ true };

void incrementKey() {
    for (int i = 0; i < 8; i++) {
        now[i]++;
        if (now[i] > 15) {
            if (i == 7) {
                flag = false;
                return;
            }
            now[i] = 0;
        }
        else {
            return;
        }
    }
}

void bytes_fromhex(unsigned char* buffer, unsigned char* result, int len) {
    for (int i = 0; i < len; i += 2) {
        result[(i >> 1)] = (buffer[i] << 4) + (buffer[i + 1]);
    }
    return;
}
void print_hex(unsigned char* buffer, int len , string prefix = "") {
    output_lock.lock();
    puts(prefix.c_str());
    for (int i = 0; i < len; i++) {
        printf("%02x", buffer[i]);
    }
    putchar('\n');
    output_lock.unlock();
    return;
}
void print_process(unsigned char* buffer, int len) {
    output_lock.lock();
    putchar('[');
    float tt = cnt.load();
    int a = (tt / full_process) * 100;
    for (int i = 0; i < a; i++) {
        putchar('=');
    }
    for (int i = 0; i < 100 - a; i++) {
        putchar(' ');
    }
    putchar(']');
    putchar('\r');
    output_lock.unlock();
    return;
}
void getNext(unsigned char* buffer , unsigned char* current) {
    // 檢查是否達到最大值
    mtx.lock();
    if (now[7] > 15) {
        flag.store(false);
        printf("\n已經沒有更多金鑰可供嘗試。\n");
        mtx.unlock();
        return;
    }
    for (int i = 0; i < 8; i++) {
        current[i] = now[i];
        current[15 - i] = now[i];
    }
    incrementKey();
    mtx.unlock();
    bytes_fromhex(current, buffer, 16);
    if (cnt % every_step == 0) {
        thread t(print_process, buffer, 8);
        t.detach();
    }
    cnt++;
    return;
}


// worker 函式，進行金鑰嘗試
void worker(unsigned char* msg,
    unsigned char* middle) {
    unsigned char key[8] = { 0 };
    unsigned char current[16] = { 0 };

    while (!found && flag) {
        getNext(key , current);
        unsigned char result[8];
        decrypt(msg, result, key);
        // print_hex(key, 8 , "Key: ");
        // print_hex(result, 8 , "Result: ");	
        // print_hex(middle, 8 , "Middle: ");
        // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        if (memcmp(result, middle, 8) == 0) {
            found = true;
            std::lock_guard<std::mutex> lock(output_lock);
            cout << "找到金鑰: ";
            for (int i = 0; i < 8; i++) {
                cout << hex << setw(2) << setfill('0') << (int)key[i];
            }
            cout << dec << endl;

            ofstream mystream("key.txt");
            mystream << "找到金鑰: ";
            for (int i = 0; i < 8; i++) {
                mystream << hex << setw(2) << setfill('0') << (int)key[i];
            }
            mystream << endl;
            mystream.close();

            return;
        }
    }
}

inline void encode(unsigned char * in , int len) {
    for(int i = 0 ; i < len; i++) {
        in[i] = (in[i]>='0' && in[i]<='9') ? in[i]-'0' : in[i];
        in[i] = (in[i]>='A' && in[i]<='Z') ? in[i]-'A'+10 : in[i];
        in[i] = (in[i]>='a' && in[i]<='z') ? in[i]-'a'+10 : in[i];
    }
    return ;
}

signed main() {


    auto start = chrono::steady_clock::now();
    unsigned char msg[8] = "TSC{";
    unsigned char in[] = "1FE01FE00EF10EF1";  // 第一把金鑰
    unsigned char pwd[8] = { 0 };
    encode(in , sizeof(in)/sizeof(in[0]));
    bytes_fromhex(in, pwd, 16);
    print_hex(pwd, 8 , "pwd: ");
    unsigned char middle[8] = { 0 };
    encrypt(msg, middle, pwd);
    print_hex(middle, 8 , "middle: ");
    printf("\nfull_process: %llu\nevery_step %llu\n\n", static_cast<unsigned long long>(full_process), static_cast<unsigned long long>(every_step));
    int num_threads = thread::hardware_concurrency();
    std::vector<std::thread> threads(num_threads);

    for (int i = 0; i < num_threads; ++i) {
        threads[i] = thread(worker, msg, middle);
    }

    // 等待所有執行緒完成
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    if (found) {
        cout << "\n破解成功！" << endl;
    }
    else {
        cout << "\n未找到正確的金鑰。" << endl;
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    printf("Elapsed time: %.2f seconds\n", elapsed_seconds.count());

    return 0;
}
