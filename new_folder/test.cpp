#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int a = 0 , b = 1;
    cout << a << ' ' << b << endl;
    for(int i = 1 ; i <= 11 ; i++) {
        cout << a + b << endl;
        int tmp = a ;
        a = b;
        b = tmp + b;
    }
return 0;
}