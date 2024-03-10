#include <bits/stdc++.h>
using namespace std;

int main() {
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> gen(1 , 5);
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n = 5 , m = 2;
    cout << n << ' ' << m << endl;
    for(int i = 0 ; i < m ; i++) {
        cout << gen(mt) << ' ' << gen(mt) << endl;
    }
    
}