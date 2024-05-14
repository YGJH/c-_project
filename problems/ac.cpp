#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 900000;

signed main() {
    int n ; 
    int q;
    cin >> n >> q;
    int tmp;
    int tmp2 , i;
    vector<set<int>> arr(n+2);
    for(i = 1 ; i <= n ; i++) {
        cin >> tmp;
        arr[i].insert(tmp); 
    }
    int tmp1;
    int cnt = 0;
    for( i = 1 ; i <= q ; i++) {
        cin >> tmp1 >> tmp2;
        cnt = arr[tmp2].size();
        for(const auto &p : arr[tmp1]) {
            bool f = true;
            for(const auto &m : arr[tmp2]) {    
                if( p == m ) {
                    f = false;
                    break;
                }
            }
            if(f) {
                arr[tmp2].insert(p);
                cnt++;
            }

        }
        arr[tmp1].clear();
        cout << arr[tmp2].size() << endl;
    }

}