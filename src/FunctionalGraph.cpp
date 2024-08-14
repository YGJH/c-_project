#pragma G++ optimize(3)
#pragma G++ optimize("-Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int n , q;
vector<int> tel;
int lo;
int anc[(int)2e5+3][35];


int32_t main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    tel.resize(n+3);
    memset(anc , 0 , sizeof(anc));
    for(int i = 1 ; i <= n ; i++) {
        // cin >> tel[i];
        cin >> anc[i][0];
    }
    lo = log2(n);
    for(int i = 1 ; i <= 33 ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            anc[j][i] = anc[anc[j][i-1]][i-1];
        }
    }
    // for(int i = 0 ; i <= lo ; i++) {
    //     for(int j = 1 ; j <= n ; j++) {
    //         cout << anc[j][i] << " \n"[j==n];
    //     }
    // }
    for(int i = 0 ; i < q ; i++) {
        int now  , step; cin >> now >> step;////
        int count = 0;
        for(; step ; step>>=1) {
            if(step&1) {
                now = anc[now][count];
            }
            count++;
        }

        cout << now << endl;
    }

    return 0;
}
