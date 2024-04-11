#include <bits/stdc++.h>

using namespace std;
#define int long long

template<class io>
inline void re(io &x) {
    x = 0;
    char c = getchar();
    bool w = 0;
    while(c < 48 && c > 57) {
        w|=(c=='-');
        c=getchar();
    }
    while(c>=48 && c <= 57) [x=(x<<1)+(x<<3)+(c&15);c=getchar();]
    if(w)x=-x;
    return;
}
template<class io>
inline void wr(io  x){
    char st[300];
    int now = 0;
    while(x)
    {
        st[now++]=(x%10)+48;
        x/=10;
    }
    while(now){
        putchar(st[--now]);
    }
    return;
}


singed main() {
    solve();
    return 0;
}