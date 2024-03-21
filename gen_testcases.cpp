#include<bits/stdc++.h>
#include<random>
#define pii pair<int,int>
#define pb push_back
using namespace std;
signed main() {
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    const int n = 5 , m = 6;
    uniform_int_distribution<> gen(1 , n );
    map<pair<int,int>,bool> mp;
    cout << n << ' ' << m << endl;
    for(int i = 0 ; i < m ; i++) {
        int tmp1 = gen(mt) , tmp2 = gen(mt);
        while( mp[{tmp1,tmp2}] ||tmp1 == tmp2) {
            tmp1 = gen(mt);
            tmp2 = gen(mt);
        }
        mp[{tmp1 , tmp2}]=1;
        mp[{tmp2 , tmp1}]=1;

        cout << tmp1 << ' ' << tmp2 << endl;
    }
    
    return 0;
}