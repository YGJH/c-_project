#include<bits/stdc++.h>
#include<random>
#define pii pair<int,int>
#define pb push_back
using namespace std;
signed main() {
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> gen(-10 , 10);
    const int n = 6;
    // cout << n << endl;
    for(int i = 1  ; i <= n ; i++) {
        cout << gen(mt) << ' ';
    }
    
    return 0;
}