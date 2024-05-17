#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(),(x).end()
int n , q;
const int N = 2e5 + 11;
int tmp , i , tmp2;
vector<unordered_map<int,bool>> contain(N);
int ans , j;
int kk;
vector<int> pa(N);
vector<int> sz(N , 1);
template<class T>
void pr(vector<T> val ,  auto & func , const string name_) {
    cerr << name_ ;
    for(j = 1 ; j <= n ; j++) {
        func(val[j]);
    }
    cerr << endl;
}
signed main() {
    cin >> n >> q;
    
    for(i = 1 ; i <= n ; i++) {
        cin >> tmp;
        (contain[i])[tmp] = 1;
        pa[i] = i;
    }
    for(i = 0 ; i < q ; i++) {
        cin >> tmp >> tmp2;
        // cerr << pa[tmp] << ' ' << pa[tmp2] << endl;
        if(sz[tmp] > sz[tmp2]) {
            for(const auto &p : contain[pa[tmp2]]) {
                (contain[pa[tmp]])[p.first] = 1;
            }
            sz[tmp2] = contain[pa[tmp]].size();
            sz[tmp] = 0;
            contain[pa[tmp2]].clear();
            cout << sz[tmp2] << endl;
            kk = pa[tmp];
            pa[tmp] = pa[tmp2];
            pa[tmp2] = kk;
        }
        else {
            for(const auto &p : contain[pa[tmp]]) {
                (contain[pa[tmp2]])[p.first] = 1;
            }
            sz[tmp2] = contain[pa[tmp2]].size();
            sz[tmp] = 0;
            contain[pa[tmp]].clear();
            cout << sz[tmp2] << endl;
        }
        // auto pp_a = [](auto a) -> void {cerr << a.size() << ' ' ;};
        // auto pp_b = [](auto b) -> void {cerr << b << ' ' ;};
        // pr(contain , pp_a , "contain: ");
        // pr(sz , pp_b , "sz: ");
        // pr(pa , pp_b , "pa: ");
        // cerr << "fin" << endl;
    }

    return 0;
}