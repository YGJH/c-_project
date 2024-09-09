#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lowbit(x) x&-x
constexpr int MXN = 2e5 + 5;
int n ;

int ar[MXN];
int d[1e6+1];
int dd[1e6+1];
int dp[1e6+1];
struct BIT{
    vector<int> bit(1e6+1, 0);
    int n = 1e6 + 1;
    void upadte(int pos , int val) {
        for( ; pos < n ; pos += lowbit(pos)) {
            bit[pos] += val;
        }
        return;
    }
    long long query(int pos) {
        long long ret = 0;
        for( ; pos ; pos -= lowbit(pos)) {
            ret += bit[pos];
        }
        return ret;
    }
}bb;
long long rang_que(int l , int r) {
    return bb.query(r) - bb.query(l-1);
}
void rang_up(int l , int r) {
    bb.update(l - 1, -1);
    bb.update(r , 1);
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(d, 0 , sizeof(d));
    memset(dd, 0 , sizeof(dd));
    memset(dp, 0 , sizeof(dp));
    memset(pre, 0 , sizeof(pre));
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> ar[i];
        dp[ar[i]]++;
        d[ar[i]]++;
        dd[ar[i]]++;

    }


    return 0;
}