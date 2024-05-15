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
int ans;
signed main() {
    cin >> n >> q;
    for(i = 1 ; i <= n ; i++) {
        cin >> tmp;
        (contain[i])[tmp] = 1;
    }
    for(i = 1 ; i <= q ; i++) {
        cin >> tmp >> tmp2;
        ans = contain[tmp2].size();
        if(contain[tmp].size() == 0) {
            cout << ans << endl;
            contain[tmp].clear();
            continue;
        }
        else if(ans == 0) {
            cout << contain[tmp].size() << endl;
            for(const auto &p : contain[tmp]) {
                (contain[tmp2])[p.first] = 1;
            }
            contain[tmp].clear();
            continue;
        }
        for(const auto &p : contain[tmp]) {
            if((contain[tmp2])[p.first]==0) {
                ans++;
                (contain[tmp2])[p.first] = 1;
            }        
        }
        contain[tmp].clear();
        cout << ans << endl;
    }
    return 0;
}