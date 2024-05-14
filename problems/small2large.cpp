#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(),(x).end()
int n , q;
const int N = 2e5 + 11;
int arr[N];
int pa[N];
int sz[N];
int i , tmp1 , tmp2;
vector<set<int>> contain(N);
int tar[N];
int findd(int a) {
    return (pa[a] == a) ? a : pa[a] = findd(pa[a]);
}
void merge(int a , int b) {
    a = findd(a) , b = findd(b);
    // a = pa[a] , b = pa[b];
    cerr << "a: " << a << " b: " << b << endl;
    if(sz[a] > sz[b]) {
        pa[b] = a;
        swap(a , b);
    }
    for(const auto &p : contain[a]) {
        contain[b].insert(p);
    }
    tar[a] = 0;
    sz[tar[b]] = contain[tar[b]].size();
    sz[tar[a]] = 0;
    contain[tar[a]].clear();
    for(const auto &p : contain[tar[b]]) {
        cerr << p << ' ';
    }
    cerr << endl;
    cout << sz[tar[b]] << endl;
}
void solve() {

    for( i = 1 ; i <= n ; i++) {
        cin >> tmp1;
        contain[i].insert(tmp1);
    }
    for( i = 0 ; i < q ; i++) {
        cin >> tmp1 >> tmp2;
        merge(tmp1 , tmp2);
        // cout << sz[findd(tmp2)] << endl;

    }
}

signed main() {
ios_base::sync_with_stdio(0);
cin.tie(0);
    cin >> n >> q;
    for(i = 0 ; i <= n + 1 ; i++) {
        sz[i] = 1;
        pa[i] = i;
        tar[i] = i;
    }
    sz[0] = 0;
    solve();


return 0;

}