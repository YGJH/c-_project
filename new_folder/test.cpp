#include <bits/stdc++.h>
using namespace std;
using ll = long long;
namespace m{
    ll ret = 1;
    ll pow(ll a, ll b) {
        for(; b ; b >>= 1 , a *= a) {
            if(b&1) {
                ret *= a;
            }
        }
        return ret;
    }
}
int32_t main() {
    cout << (5e8 > m::pow(2, 21)) << endl;
return 0;
}