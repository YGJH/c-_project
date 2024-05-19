#include<bits/stdc++.h>
#include<random>
#define pii pair<int,int>
#define pb push_back
using namespace std;
signed main() {
    const int N = 8;
    mt19937 now(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> gen(1 , N);
    cout << N << endl;
    int tmp1 , tmp2;
    unordered_map<int,bool> vis;
    for(int i = 2 ; i <= N; i ++) {
        tmp1 = gen(now);
        tmp2 = i;
        vis[i] = 1;
        while(vis[tmp1] || tmp2 == tmp1) {
            tmp1 = gen(now);
        }
        cout << tmp1 << ' ' << tmp2 << endl;
    }
    return 0;


}