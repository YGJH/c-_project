#include <bits/stdc++.h>
using namespace std;
const int N = 900000;

signed main() {
    int n;
    cin >> n;
    int arr[N];
    for (int i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for(int i = 1 ; i < n ; i++) {
        for(int j = i + 1 ; j <= n ; j++) {
            if(arr[j] >= arr[i]) {
                break;
            }
            else {
                ans++;
            }
        }
    }
    cout << ans << endl;
}