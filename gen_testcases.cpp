#include<bits/stdc++.h>
#include<random>
using namespace std;
signed main() {
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> gen(-90 ,90);
    int n = 4;
    cout << n << endl;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < 3; j++ ) {
            cout << gen(mt) << ' ' ;
        }
        cout << endl;
    }
    // cout << endl;
    // cout << 40 << endl;
    // for(int i = 0 ; i < 40 ; i++) {
    //     for(int j = 0 ; j < 3; j++ ) {
    //         cout << gen(mt) << ' ' ;
    //     }
    //     cout << endl;
    // }
    // // cout << endl;
    cout << 0 << endl;
    
    return 0;
}