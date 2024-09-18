#pragma GCC optimize("O3,unroll-loops")
#pragma target optimize("avx2 , bmi , bmi2 , lzcnt , popcnt")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
constexpr int INF = 1e18;
#define SZ(x) (int)x.size()
constexpr int MXN = 600;
struct Dinic {
	struct Edge {
		int v, f, re;
	};
	int n, s, t, level[MXN];
	vector<Edge> E[MXN];
	void init(int _n, int _s, int _t) {
		n = _n;
		s = _s;
		t = _t;
		for (int i = 0; i < n; i++) {
			E[i].clear();
		}
	}
	void add_edge(int u, int v, int f) {
		E[u].PB({v, f, SZ(E[v])});
		E[v].PB({u, 0, SZ(E[u]) - 1});
	}
	bool BFS() {
		for (int i = 0; i < n; i++)
			level[i] = 0xffffffffffffffff; // -1
		queue<int> que;
		que.push(s);
		level[s] = 0;
		while (!que.empty()) {
			int u = que.front();
			que.pop();
			for (auto it : E[u]) {
				if (it.f > 0 && level[it.v] == -1) {
					level[it.v] = level[u] + 1;
					que.push(it.v);
				}
			}
		}
		return level[t] != -1;
	}
	int DFS(int u, int nf) {
		if (u == t)
			return nf;
		int res = 0;
		for (auto &it : E[u]) {
			if (it.f > 0 && level[it.v] == level[u] + 1) {
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
	int flow(int res = 0) {
		while (BFS())
			res += DFS(s, INF);
		return res;
	}
}
flow;
char c;
vector<pair<int, int>> vt;
bool w = 0;
inline void re(int &a) {
	a = 0;
	w = 0;
	c = getchar();
	while (c < '0' || c > '9')
		w = (c == '-'), c = getchar();
	while (c >= '0' && c <= '9')
		a = (a << 1) + (a << 3) + (c & 15), c = getchar();
	if (w)
		a = -a;

	return;
}
char st[40];
int now ;
inline void wr(int a) {
	now = 0;
    if(a==0) {
        putchar('0');
        return ;
    }
	if (a < 0)
		putchar('-'), a = -a;
	while (a) {
		st[now++] = a % 10 + '0';
		a /= 10;
	}
	while (now) {
		putchar(st[--now]);
	}
	return;
}
bitset<MXN> vis;
	// struct Edge {
	// 	int v, f, re;
	// };
int ans = 0 ;
map<pair<int,int>,int> mp;
void dfs(int nn) {
    if(vis[nn]) return ;
    vis[nn] = 1;
    // cerr << nn << endl;
    for(auto i : flow.E[nn]) {
        if(flow.level[i.v] == -1) {
            if(mp[{nn , i.v}]) continue;
            else mp[{nn , i.v}] = 1;
            vt.PB(make_pair(nn , i.v));
            ans++;
        } else {
            dfs(i.v);
        }
    }
    return;
}
int n, m;
int tmp, tmp2;
int32_t main() {
    vis.reset();
	re(n);
	re(m);
	int source = 1, sink = n;
	flow.init(n + 2 , source, sink);
	for (int i = 0; i < m; i++) {
		re(tmp);
		re(tmp2);
		flow.add_edge(tmp, tmp2, 1);
		flow.add_edge(tmp2, tmp, 1);
	}
	flow.flow();

    dfs(source);
    wr(ans);
    // #define endl '\n'
    // cout << ans << endl;
    putchar('\n');
    for(auto &l : vt) {
        wr(l.first);
        putchar(' ');
        wr(l.second);
        putchar('\n');
        // cout << l.first << ' ' << l.second << endl;
    }
}