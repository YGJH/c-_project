#include <bits/stdc++.h>

using namespace std;
#define int unsigned long long

template<class io>
inline void re(io &x) {
    x = 0;
    char c = getchar();
    bool w = 0;
    while(c < 48 && c > 57) {
        w|=(c=='-');
        c=getchar();
    }
    while(c>=48 && c <= 57) {x=(x<<1)+(x<<3)+(c&15);c=getchar();}
    if(w)x=-x;
    return;
}
template<class io>
inline void wr(io  x){
    char st[300];
    int now = 0;
    while(x)
    {
        st[now++]=(x%10)+48;
        x/=10;
    }
    while(now){
        putchar(st[--now]);
    }
    return;
}
#define minn(a,b) (a<b)?a:b
const int N = 402;
const int INF = 0x3f3f3f3f;
int n;
vector<vector<int>> dp(401 , vector<int>(401) );
vector<int> pr(401,0);
int arr[N];
int ans = 200000000000;
#define ll long long
template<class T>
void print_vec(T v) {
    for(int i = 0 ; i < n ; i++) {
        for(int j =  0 ; j < n ; j++) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}
int divide(int l , int r) {
    if(l == r) return 0;
    if(dp[l][r]) return dp[l][r];
    dp[l][r] = 1e18;
    for(int i = l ; i <= r - 1; i++) {
        dp[l][r] = minn(dp[l][r] , divide(l, i) + divide(i+1,r)  + pr[r] - pr[l-1]);
    }
    return dp[l][r];
}
void solve() {
    re(n);
    pr[0]=0;
    arr[0]=0;
    for(int i = 1 ; i <= n ; i++ ) {
        re(arr[i]);
        pr[i] = pr[i-1]+arr[i];
    }
    cout << divide(1 , n) << endl;
    // print_vec(dp);
}
signed main() {
    solve();
    return 0;
}