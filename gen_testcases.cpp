#include<bits/stdc++.h>
#include<random>
#define pii pair<int,int>
#define pb push_back
using namespace std;
signed main() {
    mt19937 mt (chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> gen(-9 , 9);
    uniform_int_distribution<> ge(0,1);
    const int N = 4;
    cout << N << endl;
    for(int i = 0 ; i < N ; i++) {
        int kk = ge(mt);
        if(kk&1) { // horizontal
            int tmp1 ,tmp2 ,tmp3;
            tmp1 = gen(mt); tmp2 = gen(mt) ; tmp3 = gen(mt);
            if(tmp1 < tmp3)
                cout << tmp1 << ' ' << tmp2 << ' ' << tmp3 << ' ' << tmp2 << endl;
            else {
                cout << tmp3 << ' ' << tmp2 << ' ' << tmp1 << ' ' << tmp2 << endl;
            }
        }
        else {
            int tmp1 = gen(mt) , tmp2 = gen(mt) , tmp3 = gen(mt);
            if(tmp2 < tmp3) 
                cout << tmp1 << ' ' << tmp2 << ' ' << tmp1 << ' ' << tmp3 << endl;
            else {
                cout << tmp1 << ' ' << tmp3 << ' ' << tmp1 << ' ' << tmp2 << endl;
            }
        }
    }


    return 0;

}