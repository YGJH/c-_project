#include <bits/stdc++.h>
using namespace std;

bool w = 0; char c;
template<typename T>
inline void re(T& a) {
    w = 0;c = getchar();	a = 0; while (c < '0' || c > '9') w |= (c == '-'), c = getchar();
    while (c >= '0' && c <= '9') a = (a << 1) + (a << 3) + (c & 15), c = getchar();
    if (w) a = -a;
    return;
}
char st[30]; int kkkk = 0;
template<typename T>
inline void wr(T a) {
    kkkk = 0;
    if (a == 0) { putchar('0'); return; }
    if (a < 0)putchar('-'), a = -a;
    while (a) { st[kkkk++] = a % 10 + '0', a /= 10; }
    while (kkkk) { putchar(st[--kkkk]); }
    return;
}



struct node {
    int l, r, id;

    bool operator<(const node& x) const {
        if (l / unit != x.l / unit) return l < x.l;
        // 注意下面两行不能写小于（大于）等于，否则会出错（详见下面的小细节）
        if ((l / unit) & 1) return r < x.r;
        return r > x.r;
    }
};

void move(int pos, int sign) {
    // update nowAns
}
#define mxn 200003
int n , q;
node query[mxn];
void solve() {
    BLOCK_SIZE = int(ceil(pow(n, 0.5)));
    sort(querys, querys + q);
    for (int i = 0; i < q; ++i) {
        const query& q = querys[i];
        while (l > q.l) move(--l, 1);
        while (r < q.r) move(++r, 1);
        while (l < q.l) move(l++, -1);
        while (r > q.r) move(r--, -1);
        ans[q.id] = nowAns;
    }
}

signed main() {
    int n, q;
    re(n);
    re(q);
    for(int i = 0 ; i < q ; i++) {
        re(query[i].l);
        re(query[i].r);
        query[i].id = i;
    }

    solve();

    return 0;
}