#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma G++ optimize(1)
#pragma G++ optimize(2)
#pragma G++ optimize(3)
#pragma G++ optimize("Ofast")
#pragma G++ optimize("inline")
#pragma G++ optimize("-fgcse")
#pragma G++ optimize("-fgcse-lm")
#pragma G++ optimize("-fipa-sra")
#pragma G++ optimize("-ftree-pre")
#pragma G++ optimize("-ftree-vrp")
#pragma G++ optimize("-fpeephole2")
#pragma G++ optimize("-ffast-math")
#pragma G++ optimize("-fsched-spec")
#pragma G++ optimize("unroll-loops")
#pragma G++ optimize("-falign-jumps")
#pragma G++ optimize("-falign-loops")
#pragma G++ optimize("-falign-labels")
#pragma G++ optimize("-fdevirtualize")
#pragma G++ optimize("-fcaller-saves")
#pragma G++ optimize("-fcrossjumping")
#pragma G++ optimize("-fthread-jumps")
#pragma G++ optimize("-funroll-loops")
#pragma G++ optimize("-fwhole-program")
#pragma G++ optimize("-freorder-blocks")
#pragma G++ optimize("-fschedule-insns")
#pragma G++ optimize("inline-functions")
#pragma G++ optimize("-ftree-tail-merge")
#pragma G++ optimize("-fschedule-insns2")
#pragma G++ optimize("-fstrict-aliasing")
#pragma G++ optimize("-fstrict-overflow")
#pragma G++ optimize("-falign-functions")
#pragma G++ optimize("-fcse-skip-blocks")
#pragma G++ optimize("-fcse-follow-jumps")
#pragma G++ optimize("-fsched-interblock")
#pragma G++ optimize("-fpartial-inlining")
#pragma G++ optimize("no-stack-protector")
#pragma G++ optimize("-freorder-functions")
#pragma G++ optimize("-findirect-inlining")
#pragma G++ optimize("-frerun-cse-after-loop")
#pragma G++ optimize("inline-small-functions")
#pragma G++ optimize("-finline-small-functions")
#pragma G++ optimize("-ftree-switch-conversion")
#pragma G++ optimize("-foptimize-sibling-calls")
#pragma G++ optimize("-fexpensive-optimizations")
#pragma G++ optimize("-funsafe-loop-optimizations")
#pragma G++ optimize("inline-functions-called-once")
#pragma G++ optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
constexpr int INF = 1e9;
constexpr int MXN = 100000;
#define SZ(x) (int)(x).size()
#define PB push_back
int n, k;
#define SZ(X) (int)(X).size()
// constexpr int MXN = 1e5+4;
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
bitset<1000> vis;
vector<int> ans;
void dfs(int x) {
	if (vis[x])
		return;
	vis[x] = 1;
	// cerr << x << endl;
	for (auto &a : flow.E[x]) {
		if (x == 0) {
			dfs(a.v);
		}
		if (a.v > n && a.v < n + n + 1) {
			if (a.f > 0) {
				ans[a.v] = 0;
			} else {
				ans[x] = a.v - n;
				dfs(a.v - n);
			}
		}
	}
	return;
}
int con[550][550];
void solve() {
	cin >> n >> k;
	// memset(con , 0 , sizeof(con));
	if (n == 1) {
		cout << 1 << endl;
		cout << 0 << endl;
		return;
	}
	int source = 0, tt = n + n + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			con[i][j] = 1;
	ans = vector<int>(1000, 0);
	int tmp1;
	flow.init(n + n + 3, source, tt);
	// vector<int> node[k + 3];
	for (int i = 0; i < k; i++) {
		vector<int> tmp(n);
		for (auto &a : tmp) {
			cin >> a;
		}
		for(int j = 0 ; j < n ; j++) {
			for(int k = j + 1; k < n ; k++) {
				con[tmp[j]][tmp[k]]=0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		flow.add_edge(source, i, 1);
		flow.add_edge((i + n), tt, 1);
		for (int j = 1; j <= n; j++) {
			if (con[j][i] && i != j) {
				flow.add_edge(i, j + n, 1);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
	}
	cout << n - flow.flow() << endl;
	vis.reset();
	dfs(0);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	return;
}
int32_t main() {
	int T;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}