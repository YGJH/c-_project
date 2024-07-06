#include <iostream>
using namespace std;
#define ll long long
const ll MXN = 5 * 1e5;
const ll P1 = 75577;
const ll P2 = 12721;    // 多一個質數 p2
const ll MOD1 = 998244353;
pair<ll,ll> Hash[MXN];    //Hash[i] 為字串 [0,i] 的 hash值
void build(const string& s){
    pair<ll,ll> val = make_pair(0,0);
    for(int i=0; i<s.size(); i++){
        val.first = (val.first * P1 + s[i]) % MOD;
        val.second = (val.second * P2 + s[i]) % MOD;
        Hash[i] = val;
    }
}