#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl '\n'
#define mk make_pair
const int N = 5002;
int n , tmp1 , tmp2, w = 0 , b = 0;
vector<vector<int>> tr(N);
int xx[] = {1 , -1};
unordered_map<int , bool> vis;
vector<vector<int>> dta(N) ;// branch siza
// int dta[N][N];
vector<int> si(N , 0);
bool fin ;
int dfs(int now , int de) {
    vis[now] = 1;
    fin = true;
    int sum = 0;
    dta[now].resize(si[now]);
    dta[now][0] = de;
        int index = 1;
        for(auto nxt : tr[now]) {
            dta[now][index] = 0;
            if(!vis[nxt]) {
                dta[now][index] += dfs(nxt , de + 1);
                fin = false;
                sum += dta[now][index];
                index++;
            }
        }
    if(fin) {
        return 1;
    }
    return sum+1;
}

void dd(int now) {
    
}

void solve() {
    cin >> n;
    for(int i = 1 ; i < n ; i++) {
        cin >> tmp1 >> tmp2;
        tr[tmp1].pb(tmp2);
        tr[tmp2].pb(tmp1);
        si[tmp1]++;
        si[tmp2]++;
    }
    for(int i = 1 ; i <= n ; i++) {
            cerr << si[i] << ' ';
    }
    cerr << endl;
    dfs(1 , 0);
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 0 ; j < si[i] ; j++) {
            cerr << dta[i][j] << ' ';
        }
        cerr << endl;
    }
    vis.clear();
    dd(1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}