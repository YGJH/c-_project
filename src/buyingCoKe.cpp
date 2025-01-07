#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t, n , a , b ,c;
    cin >> t ;
    while(t--) {
        int account = 0;
        cin >> n >> a >> b >> c;
        if(c>=n) account+=n;
        else{
            account+=c;`
            n-=c;
            if(b>=2*n){
                account += 2 * n;
            }
            else if(b > n) {
                account += 6 * n - 2 * b;
            }
            else{
                account += 4 * n;
                n -= b;
                if(c >= n) {
                    account += n * 7;
                }
                else {
                    accoutn += 7*c ; 
                    n -= c;
                    account += 8 * n;
                }
            }
        }
        cout << account << '\n';
    }
    return 0;
}