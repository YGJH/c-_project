#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;

struct DSU
{
    int p[N];
    int sz[N];
    void init(int s)
    {
        for(int i = 0; i <= s; i++)
        {
            p[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x)
    {
        return (x == p[x] ? x : p[x] = find(p[x]));
    }
    bool dunion(int x, int y)
    {
        int aa = find(x);
        int bb = find(y);
        if(sz[aa] > sz[bb]) swap(aa, bb);
        if(aa == bb)
        {
            return 0;
        }
        p[aa] = bb;
        sz[bb] += sz[aa];
        return 1;
    }
}dd;

struct da {
    int u, v, w;
    bool operator<(const da& a) const {
        return w > a.w;
    }
};

struct daa {
    int p, h, index;
    bool operator<(const daa& a) const {
        return h > a.h;
    }
};

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    dd.init(n + 10);
    vector<da> v(m);
    for(int i = 0; i < m; i++) {
        cin >> v[i].u >> v[i].v >> v[i].w;
    }
    vector<daa> qq(q);
    for(int i = 0; i < q; i++) {
        cin >> qq[i].p >> qq[i].h;
        qq[i].index = i;
    }
    sort(v.begin(), v.end());
    sort(qq.begin(), qq.end());

    vector<int> ans(q, 0);
    int j = 0;
    if(v.size() == 0) {
        // assert(0);
        for(int i = 0; i < q; i++) {
            cout << "1\n";
        }
        return;
    }
    while(j < q && qq[j].h > v[0].w) ans[qq[j].index] = 0, j++;
    for(int i = 0; i < m; i++) {
        dd.dunion(v[i].u, v[i].v);
        if(i != m - 1) {
            int nxt = v[i + 1].w;
            while(j < q && qq[j].h > nxt) ans[qq[j].index] = dd.sz[dd.find(qq[j].p)], j++;
        }
    }
    while(j < q) ans[qq[j].index] = dd.sz[dd.find(qq[j].p)], j++;
    for(int i = 0; i < q; i++) {
        if(ans[i] == 0) ans[i] = 1;
        cout << ans[i] << '\n';
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    solve();
}