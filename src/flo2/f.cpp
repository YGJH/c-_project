#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) (int)(X).size()
#define PB push_back
constexpr int MXN = 5000;
constexpr int INF = 1e15;
struct Dinic
{
    struct Edge
    {
        int v, f, re;
    };
    int n, s, t, level[MXN];
    vector<Edge> E[MXN];
    void init(int _n, int _s, int _t)
    {
        n = _n;
        s = _s;
        t = _t;
        for (int i = 0; i < n; i++)
            E[i].clear();
    }
    void add_edge(int u, int v, int f)
    {
        E[u].PB({v, f, SZ(E[v])});
        E[v].PB({u, 0, SZ(E[u]) - 1});
    }
    bool BFS()
    {
        for (int i = 0; i < n; i++)
            level[i] = -1;
        queue<int> que;
        que.push(s);
        level[s] = 0;
        while (!que.empty())
        {
            int u = que.front();
            que.pop();
            for (auto it : E[u])
            {
                if (it.f > 0 && level[it.v] == -1)
                {
                    level[it.v] = level[u] + 1;
                    que.push(it.v);
                }
            }
        }
        return level[t] != -1;
    }
    int DFS(int u, int nf)
    {
        if (u == t)
            return nf;
        int res = 0;
        for (auto &it : E[u])
        {
            if (it.f > 0 && level[it.v] == level[u] + 1)
            {
                int tf = DFS(it.v, min(nf, it.f));
                res += tf;
                nf -= tf;
                it.f -= tf;
                E[it.v][it.re].f += tf;
                if (nf == 0)
                    return res;
            }
        }
        if (!res)
            level[u] = -1;
        return res;
    }
    int flow(int res = 0)
    {
        while (BFS())
            res += DFS(s, 2147483647);
        return res;
    }
} flow;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , m;
    cin >> n >> m;
    int wei[n+3];
    constexpr int source = 0 ; 
    int tar = n + m + 2;
    flow.init(n + m + 4 , source , tar);
    for(int i = 1 ; i <= n ; i++) {
        cin >> wei[i];
    }
    int sum = 0;
    for(int i = n+1 ; i <= m + n ; i++) {
        int u , v , f;
        cin >> u >> v >> f;
        flow.add_edge(source , i , f);
        flow.add_edge(i , u , INF);
        flow.add_edge(i , v , INF);
        sum += f;
    }
    for(int i = 1 ; i <= n ; i++) {
        flow.add_edge(i , tar , wei[i]);
    }
    cout << sum - flow.flow() << endl;

    return 0;
}