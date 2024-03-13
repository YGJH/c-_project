#include<bits/stdc++.h>
#include<random>
using namespace std;
signed main() {
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> gen(1 ,90);
    cout << 5 << endl;
    for(int i = 0 ; i < 5 ; i++) {
        for(int j = 0 ; j < 3; j++ ) {
            cout << gen(mt) << ' ' ;
        }
        cout << endl;
    }
    // cout << endl;
    cout << 5 << endl;
    for(int i = 0 ; i < 5 ; i++) {
        for(int j = 0 ; j < 3; j++ ) {
            cout << gen(mt) << ' ' ;
        }
        cout << endl;
    }
    // cout << endl;
    cout << 0 << endl;
    
    return 0;
}