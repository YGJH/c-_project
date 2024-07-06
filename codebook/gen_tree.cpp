#include<bits/stdc++.h>
#include<random>
#define ishowspeed ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define pb push_back
using namespace std;
signed main() {
    ishowspeed
    const int N = 8;
    mt19937 now(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> gen(1 , N);
    cout << N << endl;
    int tmp1 , tmp2;
    unordered_map<int,bool> vis;
    for(int i = 0 ; i < N ; i++) {
        cout << gen(now) << " \n"[i==N-1];
    }
    vis[1] = 1;
    for(int i = 2 ; i <= N ; i++) {
        tmp1 = gen(now);
        while(!vis[tmp1]) {
            tmp1 = gen(now);
        }
        vis[i]=1;
        cout << tmp1 << ' ' << i << endl;
    }
    return 0;


}