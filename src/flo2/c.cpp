#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
constexpr int INF = 1e9;
constexpr int MXN = 550;
#define SZ(x) (int)(x).size()
#define PB push_back
int n , m;
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
		for (int i = 0; i < n; i++)
			E[i].clear();
	}
	void add_edge(int u, int v, int f) {
		E[u].PB({v, f, SZ(E[v])});
		E[v].PB({u, 0, SZ(E[u]) - 1});
	}
	bool BFS() {
		for (int i = 0; i < n; i++)
			level[i] = -1;
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
			res += DFS(s, 2147483647);
		return res;
	}
} flow;
bitset<5500> vis;
vector<int> ans;
void dfs(int x) {
	if(vis[x]) return;
	vis[x]=1;
	for(auto &a : flow.E[x]) {
		if(x == 0) {
			dfs(a.v);
		}
		else {
			// cerr << a.f << ' ' << a.v << endl;
			if(a.f == 0 && a.v > n) {
				if(!vis[a.v-n])
					ans[x] = a.v-n;
				else
					ans[a.v-n] = 0;

				dfs(a.v-n);
			}

		}
	}
	return;
}
void solve() {
	cin >> n >> m;
	int tmp1;
	ans = vector<int>(5500,0);
	if(n == 1) {
		cout << 1 << endl;
		cout << 0 << endl;
		return ;
	}
	flow.init(n + n + 30, 0, n + n + 1);
	vector<vector<int>> node(m, vector<int>(n));
	for(int i = 0 ; i < m ; i++) {
		for(auto &a : node[i]) {
			cin >> a;
		}
	}
	for (int i = 0; i < m ; i++) {
		for(int j = 0 ; j < n ; j++) {
			if (j != 0) {
				flow.add_edge(node[i][j-1] , node[i][j] + n , 1);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		flow.add_edge(0, i, 1);
		flow.add_edge(i + n, n + n + 1, 1);
	}
	cout << flow.flow() << endl;
	vis.reset();
	dfs(0);
	for(int i = 1 ; i <= n ; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	return ;
}
int32_t main() {
	int T;
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}