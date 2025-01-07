#include <chrono>
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#define int long long 
std::mutex m;
int num = 0;
void incre() {
    int ret = 0;
    for(int i = 0 ; i < 1e10 ; i++) {
        ret++;
    }
    m.lock();
    num += ret;
    m.unlock();
    return ;
}
signed main() {
    std::chrono::high_resolution_clock::time_point st = std::chrono::high_resolution_clock::now();
    std::queue<std::thread> que;
    for(int i = 0 ; i < 10 ; i++) {
        que.push(std::thread(incre));
       // incre();
    }
    std::cout << num << std::endl;
    while(que.empty() == 0) {
         //que.front().detach();
        que.front().join();
        que.pop();
    }
    std::chrono::high_resolution_clock::time_point en = std::chrono::high_resolution_clock::now();
    auto dur = en - st;
    std::cerr << dur.count() << std::endl;
    std::cerr << num << std::endl;
    return 0;


}
