#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ishowspeed ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define mk make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define ll long long

const int N = (ll)2e5+10;
vector<vector<int>> con(N);
int n , q;
vector<vector<int>> anc(N , vector<int> (19, 0));
void dfs(int now) {
    for(int i =  1 ; i <= log2(n) ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            anc[j][i] = anc[anc[j][i-1]][i-1];
        }
    }
}

void f(int now , int k) {
    int tmp = 0;
    for( ; k ; k >>= 1 , tmp++) {
        if(k & 1) {
            now = anc[now][tmp];
        }
    }
    if(now) {
        cout << now << endl;
    }
    else
        cout << -1 << endl;
}
void solve() {
    cin >> n >> q;
    int tmp; 
    for(int i = 2 ; i <= n ; i++) {
        cin >> tmp;
        anc[i][0] = tmp;
    }
    int x , k;
    // for(int i = n ; i > 1 ; i-- )
        dfs(n);
    int ans ;
    while(q--) {
        cin >> x >> k;
        f(x , k);
    }

}

signed main() {
    ishowspeed

    solve();
    return 0;
}