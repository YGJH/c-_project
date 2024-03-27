#include<bits/stdc++.h>
#include<random>
#define pii pair<int,int>
#define pb push_back
using namespace std;
signed main() {
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    const int n = 6, m = 8;
    uniform_int_distribution<> gen(1 , n);
    cout << n << ' ' << m << endl;
    map<pii,bool> mp;
    for(int i = 0 ; i < m ; i++ ) {
        int t1 = gen(mt),  t2 = gen(mt);
        while(mp[{t1,t2}] || t1 == t2 ) {
            t1 = gen(mt);
            t2 = gen(mt);
        }
        mp[{t1,t2}]=1;
        mp[{t2,t1}]=1;
        cout << t1 << ' ' << t2 << endl;
    }
    
    return 0;
}