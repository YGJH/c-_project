#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define ishowspeed ios_base::sync_with_stdio(0),cin.tie(0);
#define pb push_back
#define int long long
#define pii pair<int,int> 
#define all(x) (x).begin(),(x).end()

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

typedef struct {
    int x1 , y1 , x2 , y2;
}Line;
vector<Line> hor;
vector<Line> ver;

bool cmp(Line a , Line b) {
    return a.x1 < b.x1;
}

void solve() {
    int n;
    int t1 , t2 , t3 , t4;
    re(n);

    for(int i = 0 ; i < n ; i++) {
        re(t1) ; re(t2) ; re(t3) ; re(t4);
        if(t2 == t4) {// hor 
            hor.pb({t1 , t2 , t3 , t4});
        }
        else {
            ver.pb({t1,t2,t3,t4});
        }
    }

    sort(all(hor),cmp);
    
    sort(all(ver) , cmp);
    int cnt = 0;
    for(auto now:hor) {
        for(auto i : ver ) {
            if(i.x1 > now.x2) {
                break;
            }
            else if(i.x1 >= now.x1 && i.y1 <= now.y1 && i.y2 >= now.y1) {
                cnt++;
            }
        }
    }
    wr(cnt);
    return;
}

signed main() {
    ishowspeed
    solve();
    return 0;
}
