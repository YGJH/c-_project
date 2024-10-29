#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int arr[] = { 5, 3, 2, 0, 14, 5 };
    int n = sizeof(arr) / sizeof(int);

    // 使用遞迴 Lambda 實現分治排序
    function<void(int* l , int * r)> cdq = [&](int* l, int* r) {
        if (r - l <= 1) return;  // 基準條件，當子陣列大小為1時停止遞迴
        auto m = l + (r - l) / 2; // 中點
        cdq(l, m);                // 遞迴處理左半部分
        cdq(m, r);                // 遞迴處理右半部分
        inplace_merge(l, m, r);   // 合併已排序的兩部分
    };

    cdq(arr, arr + n);  // 對整個陣列進行排序

    for (int a : arr) {
        cout << a << ' ';
    }
}