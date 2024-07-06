#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ld long double

int cas;
int n;
constexpr ld PI = 3.1415926535897932384626433832795028841971;
constexpr ld rad = 0.01745329251994330;

struct Pt{
    ld x,y;
    Pt(){}
    Pt(ld _x,ld _y){
        x=_x,y=_y;
    }
    bool operator<(const Pt &a) const {
        return x < a.x || (x == a.x && y < a.y);
    }
    bool operator!=(const Pt &a) const {
        return x != a.x || y != a.y;
    }
    friend ld cross(const Pt & o,const Pt & a,const Pt & b){
        Pt lhs ((o.x-a.x) , (o.y-a.y));
        Pt rhs ((o.x-b.x) , (o.y-b.y));
        return ((lhs.x*rhs.y) - (lhs.y*rhs.x));
    }
};
vector<Pt> node;
vector<Pt> ans;
ld angle , si , co;
Pt init , las;
Pt tmp;
ld x , y , w , h , sieta;
ld area;
ld aa = 0;
ld a , b;
void pr(vector<Pt> b , const string &ss) {
    cerr << ss ;
    for(const auto &p : b) {
        cerr << p.x << ' ' << p.y << endl;
    }
    cerr << endl;
}
int i,top,t;
vector<Pt> convex_hull(vector<Pt> &hull){
    sort(hull.begin(),hull.end());
    top=0;
    vector<Pt> stk;
    for(i=0;i<hull.size();i++){
        while(top>=2&&cross(stk[top-2],stk[top-1],hull[i])<=(ld)0)
            stk.pop_back(),top--;
        stk.push_back(hull[i]);
        top++;
    }
    pr(stk , "before : ");
    for(i=hull.size()-2,t=top+1;i>=0;i--){
        while(top>=t&&cross(stk[top-2],stk[top-1],hull[i])<=(ld)0)
            stk.pop_back(),top--;
        stk.push_back(hull[i]);
        top++;
    }
    pr(stk , "after : " ) ; 
    stk.pop_back();
    return stk;
}
inline void tran() {
    tmp.x = (a * co) - (b * si);
    tmp.y = (a * si) + (b * co);
    tmp.x += x;
    tmp.y += y;
}

void solve() {
    cin >> n;
    for(i = 1 ; i <= n ; i++) {
        cin >> x >> y >> w >> h >> sieta;
        aa += (h * w);
        // if(sieta < 0) sieta += (long double)360;
        sieta*=-1;
        w/=(long double)2;
        h/=(long double)2;
        angle = sieta * rad;
        si = sin(angle) ; 
        co = cos(angle);
        a = -w ; b = -h;
        tran();
        node.pb(tmp);
        a = w , b = h;
        tran();
        node.pb(tmp);
        a = -w ; b = h;
        tran();
        node.pb(tmp);
        a = w ; b = -h;
        tran();
        node.pb(tmp);
    }
    ans = convex_hull(node);
    ans.push_back(ans.front());
    init.x = 0 ; init.y = 0;
    las = ans.front();
    area = 0;
    for(const auto & p : ans ) {
        area += cross(init , p , las);
        las = p;
    }
    area = abs(area);
    cout << setprecision(1) << fixed << ( (aa * 2)/ area) * (long double)100 << " %" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> cas;
    while(cas--) {
        area = 0;
        aa = 0;
        ans.clear();
        node.clear();
        solve();
    }
}