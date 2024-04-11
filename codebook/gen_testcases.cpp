#include<bits/stdc++.h>
#include<random>
#define pii pair<int,int>
#define pb push_back
using namespace std;
signed main() {
    mt19937 mt (chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> gen(1 , 1000000000);
    // uniform_int_distribution<> gen(1,5);
    const int N = 19;
    cout << N << endl;

    for(int i = 0 ; i < N ; i++) {
        cout << gen(mt) << ' ';
    }

    return 0;
}                                                                                                               