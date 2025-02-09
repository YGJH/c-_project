#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define min(a,b) (a<b)?a:b
struct Pt{
    int x , y;
    Pt(int _x = 0 , int _y = 0) : x(_x) , y(_y) {};
    bool operator<(const Pt& p){
        return atan2(y,x) < atan2(p.y, p.x);
    }
    bool operator==(const Pt &p) const{
        return x==p.x&&y==p.y;
    }
    bool operator!=(const Pt &p) const{
        return x!=p.x || y != p.y;
    }
};
struct Li{
    Pt st , en;
};
vector<Pt> gra;
vector<Li> line;
Li tmp4;
int i ;
int n;
Pt tmp;
Pt las;
Pt ant;
long double ans = INT64_MAX;
long double dis;
long double a, b;
long double area = 0;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> ant.x >> ant.y;
    cin >> n;
    for( i = 1 ; i <= n ; i++) {
        cin >> tmp.x >> tmp.y;
        gra.pb(tmp);
    }
    // sort(gra.begin() , gra.end());
    las = gra.front();
    // if(n & 1) {
        gra.pb(gra.front());
    // }
    for( const auto &p : gra ) {
        if(las!= p) {
            tmp4.st = las ; tmp4.en = p;
            line.pb(tmp4);
        }
        las = p;
    }
    // cerr << line.size() << endl;
    for(const auto now : line) {
        // cerr << now.st.x << ' ' << now.st.y << ' ' << now.en.x << ' ' << now.en.y << endl;
        area = abs( (now.st.x - ant.x) * (now.en.y - ant.y) - (now.st.y - ant.y) * (now.en.x - ant.x)) ;
        a = now.st.x - now.en.x ; b = now.st.y - now.en.y;
        dis = sqrt( a * a + b * b );
        // cerr << "dis: " << dis << " area: " << area << endl;
        // area /= 2;
        ans = min(ans , area / dis );
    }
    // cerr << ans << endl;
    cout << setprecision(10) << fixed <<  ans << endl;

}