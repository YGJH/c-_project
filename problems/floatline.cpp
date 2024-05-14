#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define mk make_pair
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
int n;
const int N = 2e5+3;
int arr[N];
int l[N] , r[N];
void solve() {
    cin >> n;
    l[0] = 1;
    r[0] = 1;
    r[n+1] = n ;
    for(int i = 1 ; i <= n ; i++) 
        cin >> arr[i] , l[i] = r[i] = i;
    for(int i = 1 ; i <= n ;i++) {
        while ( l[i] > 1 && arr[i] <= arr[l[i] - 1]) {
            l[i] = l[l[i] - 1];
        }
    }
    for(int i = n ; i >= 1 ; i--) {
        while( r[i] < n && arr[i] <= arr[r[i]+1]) {
            r[i] = r[r[i] + 1];
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++) {
        ans = max(ans , (r[i] - l[i] + 1) * arr[i]);
    }
    cout << ans << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}