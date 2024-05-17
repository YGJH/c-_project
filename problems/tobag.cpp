#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ld long double
int cas;
int n;
constexpr ld rad = 0.01745329252;
struct Pt{
    ld x,y;
    Pt(){}
    Pt(int _x,int _y){
        x=_x,y=_y;
    }
    bool operator<(const Pt &a) const {
        return x < a.x || (x == a.x && y < a.y);
    }
    bool operator==(const Pt &a) const{
        return (x==a.x && y == a.y);
    }
    bool operator!=(const Pt&a) const{
        return (x != a.x || y != a.y);
    }
    friend int cross(const Pt & o,const Pt & a,const Pt & b){
        Pt lhs (o.x-a.x , o.y-a.y);
        Pt rhs (o.x-b.x , o.y-b.y);
        return lhs.x*rhs.y - lhs.y*rhs.x;
    }
};
void pr(vector<Pt> b) {
    cerr << "ans: ";
    for(const auto &p : b) {
        cerr << p.x << ' ' << p.y << endl;
    }
}
int i , j ,top , t;
vector<Pt> convex_hull(vector<Pt> hull){
    sort(hull.begin(),hull.end());
    top=0;
    vector<Pt> stk;
    for(i=0;i<hull.size();i++){
        while(top>=2&&cross(stk[top-2],stk[top-1],hull[i])<=0)
            stk.pop_back(),top--;
        stk.push_back(hull[i]);
        top++;
    }
    for(i=hull.size()-2,t=top+1;i>=0;i--){
        while(top>=t&&cross(stk[top-2],stk[top-1],hull[i])<=0)
            stk.pop_back(),top--;
        stk.push_back(hull[i]);
        top++;
    }
    stk.pop_back();
    return stk;
}
vector<Pt> node;
vector<Pt> ans;
ld angle , si , co;
Pt init , las;
Pt tmp;
ld x , y , w , h , sieta;
ld area = 0;
ld aa = 0;
ld a , b;
void solve() {
    cin >> n;
    for(i = 1 ; i <= n ; i++) {
        cin >> x >> y >> w >> h >> sieta;
        aa += h * w;
        w/=2;h/=2;
        angle = sieta * rad;
        si = sin(angle) ; co = sqrt(1 - si*si);
        /*
        cos -sin
        sin cos
        */ 
        a = h , b = w;
        tmp.x = a * co - b * si;
        tmp.y = a * si + b * co;
        tmp.x += x;
        tmp.y += y;
        node.pb(tmp);
        a = -h ; b = w;
        tmp.x = a * co - b * si;
        tmp.y = a * si + b * co;
        tmp.x += x;
        tmp.y += y;
        node.pb(tmp);
        a = h ; b = -w;
        tmp.x = a * co - b * si;
        tmp.y = a * si + b * co;
        tmp.x += x;
        tmp.y += y;
        node.pb(tmp);
        a = -h ; b = -w;
        tmp.x = a * co - b * si;
        tmp.y = a * si + b * co;
        tmp.x += x;
        tmp.y += y;
        node.pb(tmp);

    }
    // pr(node);
    ans = convex_hull(node);
    // pr(ans);
    las = ans.front();
    init = ans.front();
    for(const auto & p : ans) {
        area += abs(cross(las , init , p));
        las = p;
    }
    area /= 2;
    cout << setprecision(1) << fixed << (aa / area) * 100.0  << " %" << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> cas;
    while(cas--) {
        solve();
    }
    
}