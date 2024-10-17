#include <bits/stdc++.h>
using namespace std;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n),R(n),L(n),val(n);
    for(auto &c:v) cin >> c;
    set<tuple<int,int,int>> stp;
    int l = 0;
    for(int i = 1; i < n;++i){
        if(v[i] != v[i-1]) {
            stp.emplace((i-l),-l,i-1);
            L[i-1] = l; R[l] = i-1; val[i-1] = val[l] = i-l;
            l = i;
        }
    }
    stp.emplace((n-l),-l,n-1);
    R[l] = n-1; L[n-1] = l; val[l] = val[n-1] = n-l;
    int ans = 0;
    int u = 0;
    while(stp.size() > 1){
        ++ans;
        // cout <<'\n';
        // for(auto c:L) cout << c << ' ';
        // cout << '\n';
        // for(auto c:R) cout << c << ' ';
        // cout <<'\n';
        // for(auto [len,l,r]:stp){
        //     cout << len << ' ' << -l << ' ' << r<<'\n';
        // }
        // cout <<'\n';
        auto [len,l,r] = *prev(stp.end());
                stp.erase(prev(stp.end()));
        l = -l;
        // if()
       if(!L[r] || !l){
        continue;
            stp.erase((tuple<int,int,int>{val[r+1],-(r+1),R[r+1]}));
            stp.emplace(val[r+1],0,R[r+1]);
            L[r+1] = 0;
            // cout << val[r+1] << ' ' << 0 <<'.'<< R[r+1] <<'\n';
        }
        else if(R[l] == n-1 || r == n-1){
            continue;
            stp.erase((tuple<int,int,int>{val[l-1],-L[l-1],l-1}));           
            stp.emplace(val[l-1],-L[l-1],n-1);
            R[l-1] = n-1;
            // cout << val[l-1] << ' ' << -L[l-1] <<'.'<< n-1 <<'\n';
        }
        else if(l && r < n-1 && v[l-1] == v[r+1]){
            int cur = val[l-1] + val[r+1];
            stp.erase((tuple<int,int,int>{val[l-1],-L[l-1],l-1}));
            stp.erase((tuple<int,int,int>{val[r+1],-(r+1),R[r+1]}));
            val[L[l-1]] = val[R[r+1]] = cur;
            R[L[l-1]] = R[r+1],L[R[r+1]] = L[l-1];
            stp.emplace(cur,-L[l-1],R[r+1]);
        } 
        // cout << '\n';
        // if(ans > 10) break;
    }
    cout << ans+1 << '\n';
    return 0;
}