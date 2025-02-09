#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e6+10;


struct Tun{
    int a, b, c;
    bool operator<(const Tun  &aa) const{
        return c > aa.c;
    }
};
// tun a tun b
// a < b
struct Veh{
    int p , h , id;
    bool operator<(const Veh &aa) const{
        return h > aa.h;
    }
};
int ans[N];
Tun T[N];
Veh V[N];
int con[N];
int sz[N];

int find(int a) {
    return (con[a] == a) ? a : con[a] = find(con[a]);  
}
void merge(int a , int b) {
    int aa = find(a);
    int bb = find(b);
    if(sz[aa] > sz[bb]) swap(a , b);
    if(aa == bb) return ;
    sz[bb] += sz[aa];
    con[aa] = bb;
}
// void prin_con(int n_is) {
//     for(int i = 0 ; i < n_is + 1; i++) {
//         cout << sz[i] << ' ' ;
//     }
//     cout << endl << endl;
// }

void solve(){
    int n_is , n_tun, n_ve;
    cin >> n_is >> n_tun >> n_ve;
    for(int i = 0 ; i < n_is + 2 ; i++) con[i] = i, sz[i] = 1;
    for(int i = 0 ; i < n_tun ; i++){
        cin >> T[i].a >> T[i].b >> T[i].c ;
    }
    for(int i = 0 ; i < n_ve ; i++) {
        cin >> V[i].p >> V[i].h;
        V[i].id = i;
    }
    sort(V , V + n_ve);
    sort(T , T + n_tun);
    int j = 0;
    for(int i = 0 ; i < n_ve ; i++) {
        while(T[j].c >= V[i].h && j < n_tun){
            merge(T[j].a , T[j].b);
            j++;
        }
        // prin_con(n_is);
        ans[V[i].id] = sz[find(V[i].p)];
    }
    // cout << sz[finddd(1)] << endl;
    for(int i = 0 ; i < n_ve ; i++) {
        cout << ans[i] << endl;
    }

}


signed main() {
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    solve();
}