#include <windows.h>
#include <iostream>

// 共享資源
int shared_counter = 0;
// 定義臨界區
CRITICAL_SECTION cs;

// 執行緒函數
DWORD WINAPI ThreadFunction(LPVOID param) {
    int thread_id = *(int*)param;

    // 模擬多次操作
    for (int i = 0; i < 5; ++i) {
        // 進入臨界區
        EnterCriticalSection(&cs);

        // 增加共享計數器
        ++shared_counter;
        std::cout << "Thread " << thread_id << " incremented counter to " << shared_counter << "\n";

        // 離開臨界區
        LeaveCriticalSection(&cs);

        // 模擬其他工作
        Sleep(50); // 暫停 50 毫秒
    }

    return 0;
}

int main() {
    // 初始化臨界區
    InitializeCriticalSection(&cs);

    const int num_threads = 4;
    HANDLE threads[num_threads];
    int thread_ids[num_threads];

    // 建立執行緒
    for (int i = 0; i < num_threads; ++i) {
        thread_ids[i] = i + 1;
        threads[i] = CreateThread(
            NULL,                  // 預設安全屬性
            0,                     // 預設堆疊大小
            ThreadFunction,        // 執行緒函數
            &thread_ids[i],        // 傳遞參數
            0,                     // 預設執行緒選項
            NULL                   // 不需要取得執行緒 ID
        );

        if (threads[i] == NULL) {
            std::cerr << "Failed to create thread " << i + 1 << "\n";
            return 1;
        }
    }

    // 等待所有執行緒結束
    WaitForMultipleObjects(num_threads, threads, TRUE, INFINITE);

    // 關閉執行緒句柄
    for (int i = 0; i < num_threads; ++i) {
        CloseHandle(threads[i]);
    }

    // 刪除臨界區
    DeleteCriticalSection(&cs);

    // 顯示最終結果
    std::cout << "Final counter value: " << shared_counter << "\n";

    return 0;
}
