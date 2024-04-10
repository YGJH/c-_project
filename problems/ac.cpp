#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ishowspeed ios_base::sync_with_stdio(0);cin.tie(0);

inline void printT(int a[], int siz){
    for(int i = 0 ; i < siz ; i++) {
        cerr << a[i] <<  ' ' ;
    }
    cerr << endl;
}
signed main() {
    ishowspeed
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    int ANS = 0 ;
    int k = n;
    while(n > 2) {
        int minn = INT32_MAX;
        int index;
        for(int i = k - n + 1 ; i < k ; i++) {
            if(arr[i] + arr[i-1] < minn) {
                minn = arr[i] + arr[i-1];
                index = i;
            }
        }
        ANS += minn;
        arr[index] = minn;
        for(int i = index-1; i > 0 ; i--) {
            arr[i] = arr[i-1];
        }
        // printT(arr , k);
        n--;
    }
    ANS += arr[k-1] + arr[k-2];
    cout << ANS;


    return 0;
}