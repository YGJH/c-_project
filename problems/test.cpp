#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 100;
vector<vector<int>> rou(1000);
unordered_map<int, bool> vis;
vector<int>tour;
int timing=0;
int in[N],out[N];
void dfs(int u,int fa){
    cerr << u << ' ' << fa << endl;
    tour.push_back(u);//進入的時間點
    in[u]=tour.size()-1;
    for(auto v:rou[u]){
        if(v==fa)continue;
        dfs(v,u);
        tour.push_back(u);//走完其中一個孩子 再走回自己
    }
    out[u]=tour.size()-1;
}


signed main() {
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        int a , b;
        cin >> a >> b;
        rou[a].pb(b);
        rou[b].pb(a);
    }
    dfs(1 , 1);
    for (int i = 1; i <= 8 ; i++) {
        cout <<  i << ": " << in[i] << ' ' << out[i] << endl;
    }
    for (auto i : tour) {
        cout << i <<  ' ';
    }
}


