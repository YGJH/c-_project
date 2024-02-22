#include <bits/stdc++.h>
using namespace std;
#define int __int128
const int MOD = 1e9+7;
template<class io>
inline void re(io &x){
    x=0;
    bool w=0;
    char c = getchar();
    while(c!='-'&&c<'0' && c > '9'){
        c=getchar();
    }
    if(c=='-'){
        w=1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    if(w)x=-x;
}
template<class io>
inline void wr(io x){
    if(x<0)putchar('-') , x=-x;
    static char tmp[50];
    short now = 0;
    while(x){
        tmp[now++]=(x%10)+48;
        x/=10;
    }
    while(now>=0){
        putchar(tmp[--now]);
    }
}
inline int poww(int a , int b){
    int ret = 1;
    for(; b ; b>>= 1 , a*=a%MOD){
        if(b&1)
            ret *= a, ret%=MOD;
        a%=MOD;
    }
    return ret;
}

signed main() {
    int a, b;
    re(a) , re(b);
    int p = 1 , q = 1;
    int now = a , now2 = 1;
    if(b>a/2)b=a-b;
    for(int i = 0 ; i < b ; i++) {
        p*=(now--)%MOD;
        q*=(now2++)%MOD;
        p%=MOD;q%=MOD;
        // wr(p) , putchar(' ') , wr(q);
        // wr(p) , putchar(' '), wr(q);
        // putchar('\n');
        // putchar('\n');
    }
    int tmp = poww(q , MOD-2);
    tmp = p*tmp;
    tmp%=MOD;
    wr(tmp);
    return 0;
}