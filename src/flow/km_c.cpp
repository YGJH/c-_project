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
constexpr int MXN = 300;
using ll = long long;
#define int long long
constexpr int INF = 1e18;
vector<pair<int, int>> rot;
int n;
bool w;
char c;
inline void re(int &a) {
	a = 0;
	w = 0;
	c = getchar();
	while (c < 48 || c > 57)
		w |= (c == '-'), c = getchar();
	while (c >= 48 && c <= 57)
		a = (a << 1) + (a << 3) + (c & 15), c = getchar();
	if (w)
		a = -a;
	return;
}
int x;
char st[40];
inline void wr(int a) {
	x = 0;
	if (a == 0) {
		putchar('0');
		return;
	}
	if (a < 0)
		putchar('-'), a = -a;
	while (a) {
		st[x++] = a % 10 + 48;
		a /= 10;
	}
	while (x) {
		putchar(st[--x]);
	}
	return;
}
struct KM { // max weight, for min negate the weights
	int n, mx[MXN], my[MXN], pa[MXN];
	ll g[MXN][MXN], lx[MXN], ly[MXN], sy[MXN];
	bool vx[MXN], vy[MXN];
	void init(int _n) { // 1-based, N個節點
		n = _n;
		for (int i = 1; i <= n; i++)
			fill(g[i], g[i] + n + 1, 0);
	}
	void addEdge(int x, int y, ll w) {
		g[x][y] = w;
	} //左邊的集合節點x連邊右邊集合節點y權重為w
	void augment(int y) {
		for (int x, z; y; y = z)
			x = pa[y], z = mx[x], my[y] = x, mx[x] = y;
	}
	void bfs(int st) {
		for (int i = 1; i <= n; ++i)
			sy[i] = INF, vx[i] = vy[i] = 0;
		queue<int> q;
		q.push(st);
		for (;;) {
			while (q.size()) {
				int x = q.front();
				q.pop();
				vx[x] = 1;
				for (int y = 1; y <= n; ++y)
					if (!vy[y]) {
						ll t = lx[x] + ly[y] - g[x][y];
						if (t == 0) {
							pa[y] = x;
							if (!my[y]) {
								augment(y);
								return;
							}
							vy[y] = 1, q.push(my[y]);
						} else if (sy[y] > t)
							pa[y] = x, sy[y] = t;
					}
			}
			ll cut = INF;
			for (int y = 1; y <= n; ++y)
				if (!vy[y] && cut > sy[y])
					cut = sy[y];
			for (int j = 1; j <= n; ++j) {
				if (vx[j])
					lx[j] -= cut;
				if (vy[j])
					ly[j] += cut;
				else
					sy[j] -= cut;
			}
			for (int y = 1; y <= n; ++y)
				if (!vy[y] && sy[y] == 0) {
					if (!my[y]) {
						augment(y);
						return;
					}
					vy[y] = 1, q.push(my[y]);
				}
		}
	}
	ll solve() { // 回傳值為完美匹配下的最大總權重
		fill(mx, mx + n + 1, 0);
		fill(my, my + n + 1, 0);
		fill(ly, ly + n + 1, 0);
		fill(lx, lx + n + 1, -INF);
		for (int x = 1; x <= n; ++x)
			for (int y = 1; y <= n; ++y) // 1-base
				lx[x] = max(lx[x], g[x][y]);
		for (int x = 1; x <= n; ++x)
			bfs(x);
		ll ans = 0;
		for (int y = 1; y <= n; ++y) {
			ans += g[my[y]][y];
			rot.push_back(make_pair(my[y], y));
		}
		return ans;
	}
} graph;
int ans;
int tmp;
int i, j;
int32_t main() {
	re(n);
	graph.init(n);
    // cerr << n << endl;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			re(tmp);
            // cerr << tmp << endl;
			graph.addEdge(j, i, -tmp);
		}
	}
	ans = graph.solve();
	wr(-ans);
	putchar('\n');
	for (auto &a : rot) {
		wr(a.second);
		putchar(' ');
		wr(a.first);
		putchar('\n');
	}
}
