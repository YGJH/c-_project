// A = i + b/2 - 1
// A: Area of polygon
// i: Grid number in the inner
// b: Grid number on the side
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define PI acos(-1);
#define ld long double
ld x , y , r;
ld area = 0;
ld i;
void solve() {
    cin >> x >> y >> r;
    area = (r * r)  * PI;

    int I = 0;
    int kx = x - r - 1;
    int px = x + r + 1;
//  y=  sqrt ( r * r  - ( x - k ) ^ 2  ) + b
// (x - k)_^ 2 + ( y - b ) ^ 2 = r ^ 2
    for(i=kx ; i <= px ; i++) {
        ld yyd =  (r * r) - (i - x ) * ( i - x )  ;
        if(yyd < 0) continue;
        else { yyd = sqrt(yyd) + y;}
        int yyi = sqrt (  (r * r) - (i - x ) * ( i - x ) ) + y ;
        cerr << yyi << ' ' << yyd << endl;
        if(yyi == yyd && (i != (int) x - r || i !=  (int) x + r ) ) {
            I += 2;
        }
        else if(yyi == yyd) {
            I++;
        }
    }
    cout << I << endl;
    // area = i + b / 2 - 1;
    // b = (area -i + 1) * 2; 
    cout << (int)(I +( ( area - I +  1 ) * 2 ))<< endl; 
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}