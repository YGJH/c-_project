#include <iostream>
#include <mutex>
#include <thread>
#include <queue>
#include <semaphore>
#include <syncstream>
using namespace std;
using namespace std::chrono_literals;
std::counting_semaphore lock1(1);
std::counting_semaphore lock2(1);

void func1() {
    
    lock1.acquire();
    lock2.acquire();

    lock1.relase();
    lock2.relase();
}

void func2() {
    lock2.acquire();
    lock1.acquire();
    lock1.relase();
    lock2.relase();
}




signed main() {
    thread a(func1);thread b(func2);;
    return 0;
}
    

