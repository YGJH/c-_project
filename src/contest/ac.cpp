#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int mxn = 2e5 + 3;
int ar1[mxn];
int ar2[mxn];
#define lowbit(x) x&-x
struct Binary_Indexed_Tree{
    int n;
    vector<long long> bit;

    void init(int _n){
        n = _n+1;
        bit = vector<long long>(n,0);
    }
    void update(int x,int v){
        for(; x<n; x+=lowbit(x)){
            bit[x] += v;
        }
    }
    long long query(int x){
        long long ret = 0;
        for(; x>0; x-=lowbit(x)){
            ret += bit[x];
        }
        return ret;
    }
}bit;
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    bit.init(mxn);
    for(int i = 1 ; i <= n+1 ; i++) {
        cin >> ar1[i];
        bit.update(i , ar1[i] * (1 << (n-i+1)) );
        // cerr << ar1[i] * (1 << (n-i+1)) << endl;
    }
    bool f = false;
    
    for(int i = 1 ; i <= n+1 ; i++) {
        cin >> ar2[i];
        
    }
    int ans = 0;
    int r = n + 1;
    for( ; r >= 1 && !f ; r--) {
        if(ar2[r] > 0) {
            if(ar2[r] <= ar1[r]) {
                continue;
            }
            for(int i = 1 ; i <= r ; i++) {
                int k =(bit.query(r) - bit.query(i));
                if(ar1[i] > 0 || i == r) {
                            if(i == r) {
                                if(ar1[r] < ar2[r]) {
                                    f = true;
                                    break;
                                }
                                else{
                                    ar2[r] = 0;
                                    ar1[r] = 0;
                                    break;
                                }
                            }
                            if((ar2[r]*(1<<(n-r+1)) - k) <= 0) {
                                continue;
                            }
                            int mp = ((ar2[r]*(1<<(n-r+1))) - k) / (1<<(n-i+1));
                            while( (ar2[r]*(1<<(n-r+1)) - k) > (1 << (n-i+1)) * mp) mp++;
                            if(i < r) {
                                ans += mp;
                            }
                            ar1[i] -= mp;
                            if(ar1[i] < 0) {
                                f=true;
                                break;
                            }
                            bit.update(i, - (mp * (1 << (n-i+1))) );
                            if(i < n+1) {
                                ar1[i+1] += (mp) * 2;
                                bit.update(i+1, (mp) * 2 * (1 << (n-i)) );
                            }
                }
            }
            if(ar2[r] > 0) {
                f = true;
                break;
            }
        }
    }
    if(f) {
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }


    return 0;
}