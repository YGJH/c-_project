#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
#define int long long
#define ishowspeed ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pii pair<int,int>
#define pll pair<long long , long long>

inline void wr(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    int now = 0;
    char tmp[300];
    while(x) {
        tmp[now++] = (x % 10) + 48; x /= 10;
    }
    while(now) {
        putchar(tmp[--now]);
    }
    return ;
}
inline void re(int &x) {
    char c = getchar();
    x = 0;
    bool w = false;
    while(c < 48 && c > 57) {
        c = getchar();
        w |= (c == '-');
    }
    while(c > 47 && c < 58)x=(x<<3)+(x<<1)+(c&15),c=getchar();
    if(w)x=-x;
    return ;
}
tree<pll , null_type , less<pll> , rb_tree_tag , tree_order_statistics_node_update> s;
signed main() {
    int n , m ;
    int now = 0;
    re(n) ; re(m);
    unordered_map<int,int> mp;
    s.insert({1000000 , 1});
    int t1 ,t2;
    bool fi = 1;
    mp[1] = 1000000;
    for(int i = 0 ; i < m ; i++ ) {
        re(t1) , re(t2);
        if(mp[t1]==0){
            s.insert({t2, t1});
            mp[t1] = t2;
        }
        else{
            if(fi && t1==1) {
                s.erase({mp[1], 1});
                mp[1] = t2;
                s.insert({mp[1] , 1});
                fi = false;
            }
            else {
                s.insert({mp[t1]-1000000+t2 , t1});
                s.erase({mp[t1] , t1});
                mp[t1] = mp[t1]-1000000+t2;
            }
        }
        cout << s.order_of_key({mp[1],1}) + 1 << endl;
    }
    return 0;
}