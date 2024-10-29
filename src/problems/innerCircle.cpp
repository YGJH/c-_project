#include <bits/stdc++.h>
using namespace std;
long double rad = 0.01745329252;
const long double EP = 1e-6;
long long n , r;
signed main() {
    cin >> n >> r;
    long double ang = (long double) 360 / n;
    long double co = cos(ang * rad);
    long double a = 1 - co;
    a = sqrt(a);
    cout << setprecision(7) << fixed << (r * a / (sqrt(2) - a)) << endl;
}