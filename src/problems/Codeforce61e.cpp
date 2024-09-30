#pragma G++ optimize(1)
#pragma G++ optimize(2)
#pragma G++ optimize(3)
#pragma G++ optimize("Ofast")
#pragma G++ optimize("inline")
#pragma G++ optimize("-fgcse")
#pragma G++ optimize("-fgcse-lm")
#pragma G++ optimize("-fipa-sra")
#pragma G++ optimize("-ftree-pre")
#pragma G++ optimize("-ftree-vrp")
#pragma G++ optimize("-fpeephole2")
#pragma G++ optimize("-ffast-math")
#pragma G++ optimize("-fsched-spec")
#pragma G++ optimize("unroll-loops")
#pragma G++ optimize("-falign-jumps")
#pragma G++ optimize("-falign-loops")
#pragma G++ optimize("-falign-labels")
#pragma G++ optimize("-fdevirtualize")
#pragma G++ optimize("-fcaller-saves")
#pragma G++ optimize("-fcrossjumping")
#pragma G++ optimize("-fthread-jumps")
#pragma G++ optimize("-funroll-loops")
#pragma G++ optimize("-fwhole-program")
#pragma G++ optimize("-freorder-blocks")
#pragma G++ optimize("-fschedule-insns")
#pragma G++ optimize("inline-functions")
#pragma G++ optimize("-ftree-tail-merge")
#pragma G++ optimize("-fschedule-insns2")
#pragma G++ optimize("-fstrict-aliasing")
#pragma G++ optimize("-fstrict-overflow")
#pragma G++ optimize("-falign-functions")
#pragma G++ optimize("-fcse-skip-blocks")
#pragma G++ optimize("-fcse-follow-jumps")
#pragma G++ optimize("-fsched-interblock")
#pragma G++ optimize("-fpartial-inlining")
#pragma G++ optimize("no-stack-protector")
#pragma G++ optimize("-freorder-functions")
#pragma G++ optimize("-findirect-inlining")
#pragma G++ optimize("-frerun-cse-after-loop")
#pragma G++ optimize("inline-small-functions")
#pragma G++ optimize("-finline-small-functions")
#pragma G++ optimize("-ftree-switch-conversion")
#pragma G++ optimize("-foptimize-sibling-calls")
#pragma G++ optimize("-fexpensive-optimizations")
#pragma G++ optimize("-funsafe-loop-optimizations")
#pragma G++ optimize("inline-functions-called-once")
#pragma G++ optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long 
#define endl '\n'
#define lowbit(x) (x&-x)
#define pb push_back
const int MXN = 1e6 + 2 ;
int n , i ;
vector<int> v;
struct {
    int n ;
    vector<ll> bit;
    void init(int n_ ) {
        n = n_ + 1;
        bit = vector<int> (n,0);
        return ;
    }
    void update(int pos , int val) {
        for(; pos < n ; pos += lowbit(pos)) {
            bit[pos] += val;
        }
        return ;
    }
    ll query(int x) {
        ll ret = 0;
        for( ; x>0 ; x ^= lowbit(x)) {
            ret += bit[x];
        }
        return ret;
    }
}BIT;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    v.resize(n);
    for(auto &c : v) {
        cin >> c ;
    }
    vector<int> tmp(v);
    sort(tmp.begin() , tmp.end());
    tmp.erase(unique(tmp.begin() , tmp.end()) , tmp.end());
    for(i = 0 ; i < n ; i++) {
        v[i] = lower_bound(tmp.begin() , tmp.end() , v[i]) - tmp.begin() + 1;
    }
    BIT.init(n+10);
    vector<int> vx(n);    
    for(i = n - 1; i >= 0 ; i--) {
        vx[i] = BIT.query(v[i]-1);
        BIT.update(v[i] , 1);
    }
    BIT.init(n);
    ll ans = 0;
    for(i = n - 1 ; i >= 0 ; i--) {
        ans += BIT.query(v[i] - 1); 
        // cerr << ans << endl;
        // cerr << v[i] << ' ' << vx[i] << endl;
        BIT.update(v[i] , vx[i]);
    }
    cout << ans << endl;
    return 0;
}