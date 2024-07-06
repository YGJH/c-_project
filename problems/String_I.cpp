#include <bits/stdc++.h>
using namespace std;
#define int long long
// const int MOD = 4611686018427387847;
const int MXN = 2e5;
const int P1 = 75577;
const int P2 = 12721;    // 多一個質數 p2
const int MOD = 998244353;
map<pair<int,int> , bool> mp;
int n , i , j;
int len , req;
int h , h2;
string str;
vector<pair<int,int>> HASH;
namespace mypow{
    int pow(int a , int b) {
        int ret = 1;
        for( ; b ; b >>= 1 , a = (a * a) % MOD ) {
            if(b & 1) {
                ret *= a;
                ret %= MOD;
            }
        }
        return ret;
    }
}

void solve() {
    mp.clear();
    HASH.clear();
    cin >> len  >> req;
    str.clear();
    cin>>str;
    HASH.resize(len+3);
    
    // build hash
    pair<int,int> val = make_pair(0,0);
    for(i=0; i<len; i++){
        val.first = ((val.first * P1)%MOD + str[i]) % MOD;
        val.second = ((val.second * P2)%MOD + str[i]) % MOD;
        HASH[i+1] = val;
    }
    j = req;
    HASH[0].first = 0;
    HASH[0].second = 0;
    for(i = 0 ; i < len ; i++) {
        if(j <= len && j > 0) {
            h = ((HASH[j].first - (HASH[i].first * mypow::pow(P1 , req) % MOD)) + MOD) % MOD;
            h2 = ((HASH[j].second - (HASH[i].second * mypow::pow(P2 , req)%MOD)) + MOD) % MOD ;
            mp[{h,h2}] = 1;
        }
        else break;
        j++;
    }
    cout << mp.size() << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--) {
        solve();
    }

    return 0;
}