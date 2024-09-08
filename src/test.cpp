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
    int n ;
    cin >> n;
    stringstream ss ; ss << n;
    string str ; ss >> str;
    cout << str << endl << n << endl;


return 0;
}