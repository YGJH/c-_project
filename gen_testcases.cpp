#include <bits/stdc++.h>
using namespace std;

int main() {
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> gen(1 , 8);
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n = 8, m = 5;
    map<int,int> vis;
    cout << n << ' ' << m << endl;
    for(int i = 0 ; i < m ; i++) {
        int tmp1 , tmp2;
        tmp1 = gen(mt) , tmp2 = gen(mt);
        while(vis[tmp1] && vis[tmp2] || tmp1 == tmp2) {
            tmp1 = gen(mt);
            tmp2 = gen(mt);
        }
        cout << tmp1 << ' ' << tmp2 << endl;
        vis[tmp1]++ , vis[tmp2] ++;
    }
    return 0;
}