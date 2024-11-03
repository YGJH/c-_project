#include <bits/stdc++.h>
using namespace std;
#define int  long long
constexpr int mxn = 2e5 + 3;
int ar1[mxn];
int ar2[mxn];

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;

    for(int i = 0 ; i <= n ;i++) {
        cin >> ar1[i];
    }
    for(int i = 0 ; i <= n ;i++) {
        cin >> ar2[i];
    }
    int i = n;


    for(int j = n ; j >= 0 , i >= 0 ; --j) {
        i = j;
        while(ar2[j] > 0 && i >= 0) {
            if(ar1[j] >= ar2[j]) {
                ar1[j] -= ar2[j];
                ar2[j] = 0;
                break;
            }
            while(i >= 0 && ar1[i] <= 0 || i > j) {
                i--;
            }
            if(i < 0) goto fa;
            
            int tmp = ar2[j] - ar1[j];
            // int k = min((j - i),(long long)62);
            int k = (j - i);
            assert(k < 63);
            tmp = ceil((float)tmp / (1 << k));
            tmp = min(tmp , ar1[i]);
            int ii = i;
            for( ; ii < j ; ii++) {
                ar1[ii+1] += tmp * 2;
                ar1[ii] -= tmp;
                ans += tmp;
                // cerr << j  << ' ' << ii << ' ' << tmp << endl;
                tmp = ar2[j] - ar1[j];
                k = (j - ii - 1);
                assert(k < 63);
                tmp = ceil((float)tmp / (1 << k));
                tmp = min(tmp , ar1[ii+1]);
            }
            // cerr << ar1[j] << endl;
            ar2[j] -= min(ar1[j] , ar2[j]);
            ar1[j] = 0;
        }
        if(i < 0 && ar2[j] > 0) {
            goto fa;
        }

    }
    goto yes;
        {
            fa:
            cout << -1 << '\n';
            return 0; 
        }

        {
            yes:
            cout << ans << '\n'; 
        }



    return 0;
}