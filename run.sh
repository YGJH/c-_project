#!/bin/bash

# 編譯程式，並檢查是否成功
if ! g++ -std=c++17 -O2 ac.cpp -o ac; then
    echo "編譯 ac.cpp 失敗"
    exit 1
fi

if ! g++ -std=c++17 -O2 wa.cpp -o wa; then
    echo "編譯 wa.cpp 失敗"
    exit 1
fi

# 計數器
count=0

# 無限循環進行測試
while true; do
    ((count++))
    echo "執行測試 #$count"
    
    # 生成測試資料
    python3 gen.py > input || { echo "生成測試資料失敗"; exit 1; }
    
    # 執行兩個程式
    timeout 1s ./ac < input > ac.out
    AC_STATUS=$?
    timeout 1s ./wa < input > wa.out
    WA_STATUS=$?
    
    # 檢查程式是否超時
    if [ $WA_STATUS -eq 124 ]; then
        echo "WA 程式超時"
        break
    fi
    if [ $AC_STATUS -eq 124 ]; then
        echo "AC 程式超時"
        break
    fi
    
    # 比較輸出
    if ! diff -Z -B ac.out wa.out > /dev/null; then
        echo "找到不同！在測試 #$count"
        echo "=== 輸入 ==="
        cat input
        echo "=== AC 輸出 ==="
        cat ac.out
        echo "=== WA 輸出 ==="
        cat wa.out
        echo "=== 差異 ==="
        diff -y ac.out wa.out
        break
    fi
done