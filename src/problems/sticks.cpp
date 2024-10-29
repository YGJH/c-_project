#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define ishowspeed ios_base::sync_with_stdio(0),cin.tie(0);
#define pb push_back
#define int long long
#define pii pair<int,int> 
#define al(x) (x).begin(),(x).end()

template<class io>
inline void re(io &x) {
    io c = getchar();int w = 0 ; x = 0;
    while(c < 48 || c > 57) w|=c==45,c=getchar();
    while(c > 47 && c < 58)x=(x<<3)+(x<<1)+(c&15),c=getchar();
    x=w?-x:x;return;
}
template<class io>
inline void wr(io x){
    if(x==0){
        putchar('0');
        return;
    }
    int now = 0;
    char sta[300];
    if(x<0) putchar('-') , x=-x;
    while(x){
        sta[now++] = x%10 + 48;
        x/=10;
    }
    while(now) {
        putchar(sta[--now]);
    }
}

const int N = 1e5 + 3;

struct Line{
    int x,y1,y2,mode;
};

vector<Line> all;
bool compare(Line a,Line b){
    if(a.x==b.x)return a.mode<b.mode;
    else return a.x<b.x;
}
void add_vertical_line(int x1,int y1,int x2,int y2){
    all.push_back({x1,y1,y2,0});//mode==0代表鉛直線
}

void add_horizontal_line(int x1,int y1,int x2,int y2){
    all.push_back({x1,y1,y1,-1});//mode==-1代表水平線左側端點
    all.push_back({x2,y1,y1,1});//mode==1代表水平線右側端點
}
tree<int, null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update> L;
void solve() {
    int n;
    int t1 , t2 , t3 , t4;
    // re(n);
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        // re(t1) ; re(t2) ; re(t3) ; re(t4);
        cin >> t1 >> t2 >> t3 >> t4 ;
        if(t2 == t4) {// hor
            add_horizontal_line(t1 , t2 , t3 , t4);
        }
        else {
            add_vertical_line(t1 ,t2 , t3 , t4);
        }
    }

    sort(al(all),compare);
    // cerr << endl;
    // for(auto i : all ) {
    //     cerr << i.x << ' ' << i.y1 << ' ' << i.y2 << ' ' << i.mode << endl;
    // }
    vector<Line>::iterator it = all.begin();
    int cnt = 0;
    int tmp1 , tmp2;
    while(it!=all.end()) {
        if(it->mode == -1) {
            L.insert(it->y1);
        }
        else if(it->mode == 0) {
            tmp1 =  L.order_of_key(it->y2) - L.order_of_key(it->y1);
            // cerr << L.order_of_key(it->y2) << ' ' << L.order_of_key(it->y1) << endl;
            if(tmp1 < 0) tmp1=-tmp1;
            cnt+=tmp1;
        }
        else if(it->mode == 1){
            // cerr << L.size() << endl;
            L.erase(it->y1);
            // cerr << L.size() << endl;
        }
        it++;
    }
    // wr(cnt);
    cout << cnt << endl;
    return;
}

signed main() {
    ishowspeed
    solve();
    return 0;
}
