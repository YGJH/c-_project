#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define lowbit(x) (x&-x)
const int P1 = 75577;
const int P2 = 12721;    // 多一個質數 p2
const int MOD = 998244353;
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
#define lowbit(x) (x&-x)
struct {
    vector<int> bit;
    int _n;
    void init(int n) {
        _n = n+1;
        bit.resize(n+1,0);
    }
    long long query(int x) {
        int ret = 0;
        for( ; x ; x ^=lowbit(x)) {
            ret += bit[x];
            ret %= MOD;
        }
        return ret;
    }
    void update(int x , int v) {
        for( ; x < n  ; x += lowbit(x)) {
            bit[x] += v;
            bit[x] %= MOD;
        }
    }
}BIT1 , BIT2;


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n , q;
    cin >> n >> q;
    string str;
    cin >> str;
    pair<int,int> val = make_pair(0,0);
    vector<int> HASH(n+3);
    BIT1.init(n+2);
    BIT2.init(n+2);
    for(i=0; i<n; i++){
        val.first = ((val.first * P1)%MOD + str[i]) % MOD;
        val.second = ((val.second * P2)%MOD + str[i]) % MOD;
        // HASH[i+1] = val;
        BIT1.update(i+1, val.first);
        BIT2.update(i+1, val.second);
    }
    int instruction , l , r;
    char ch;
    
    for(int i = 0 ; i < q ; i++) {
        cin >> instruction >> l;
        if(instruction == 1) {
            cin >> ch;
            int diff = ch - str[l];
            BIT1.update(l , diff);
            BIT2.update(l , diff); 
        } 
        else {
            cin >> r;
            l--;
            if(l) {
                
            } 
        }
    }
    
    
    return 0;
}