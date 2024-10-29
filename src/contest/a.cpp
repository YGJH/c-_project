#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n  , k ;
    cin >> n >> k;
    int arr;
    int sum = 0;
    int m[n];
    int now = 0;
    for(int i = 0 ; i < n ; i++) {
        cin >> arr;
        if(arr <= 0) {
            sum += arr;
        }
        else 
        {
            m[now++] = arr;
        }
    }
    sort(m , m + now - 1);
    if(now != 0) {
        for(int i = 0 ; i < now ; i++ , k--) {
            if(k > 0)
                sum += min(m[i]*-1 , m[i]);
            else {
                sum += m[i];
            }
        }
    }
    cout << sum << endl;



    return 0;
}