#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct 2D_BIT{
    vector<vector<int>> bit;
    int n , m;
    inline ll lowbit(ll x) {
        return x&-x;
    }
    ll query(int x,  int y) {
        ll tot = 0;
        for(; y ; y -= lowbit(y)) {
            for ( ; x ; x -= lowbit(x)) {
                tot += bit[y][x];
            }
        }
        return tot;
    }
    void build(int n_ , int m_) {
        n = n_ + 1;
        m = m_ + 1;
        bit = vector<vector<int>> (n , vector<int> (m , 0));
        return ;
    }
    void update(int x,  int y , int v) {
        for ( int i = x ; i <= n ; i += lowbit(i)) {
            for (int j = y ; j <= m ; j += lowbit(j)) {
                bit[i][j] += v;
            }
        }
        return ;
    }
};
int32_t main() {return 0;}