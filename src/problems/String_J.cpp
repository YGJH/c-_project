#include <bits/stdc++.h>
using namespace std;
#define i32 int
#define pb push_back
#define i64 long long
const i32 MXN = 1e5 + 3;
const i64 P1 = 75577;
const i64 P2 = 12721;    // 多一個質數 p2 
const i64 MOD1 = 998244353;
const i64 MOD2 = 197774749;    // 多一個質數 p2
i32 n , i , j, val ,val2 ,k , tmp;
vector<vector<i32>> HASH(MXN);
vector<vector<i32>> HASH2(MXN);
string arr[MXN];
namespace fastpow{
    i64 pow(i32 a , i32 b) {
        i32 ret = 1;
        for( ; b ; b >>= 1 , a = (a * a) % MOD1) {
            if(b & 1) {
                ret *= a;
                ret %= MOD1;
            }
        }
        return ret;
    }
}
void make_hash(){
    val = 0; 
    val2 = 0;
    HASH[i].pb(0);
    for(j = 0 ; j < arr[i].length() ; j++) {
        val = (P1 * val + (arr[i])[i]) % MOD1; 
        val2 = (P2 * val2 + (arr[i])[i]) % MOD2;
        HASH[i].pb(val);
        HASH2[i].pb(val2);
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=0;i<n;i++) {
        cin >> arr[i];
        make_hash();
    }
    for(i = 1 ; i < n ; i++) {
        k = 0 ; j = arr[i].length()-1; tmp = arr[i-1].length();
        while((j>=2&&k<=tmp)&&(HASH[i-1][j] - HASH[i-1][j-2] == HASH[i][k] && HASH2[i-1][j] - HASH2[i-1][j-2] == HASH2[i][k])) {
            j--;
            k++;
        }
    }

    return 0;
}