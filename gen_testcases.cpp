#include <bits/stdc++.h>
using namespace std;

int main() {
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> gen(1 , 9);
    int n , m , k;
    n = 5;
    m = 4;
    k = 3;
    printf("%d %d %d\n" , n , m , k);
    for(int i = 0 ; i < n ; i++) {
        int tmp = gen(mt);
        printf("%d " , tmp);
    }
    printf("\n");
    return 0;
}