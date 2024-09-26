#include <bits/stdc++.h>
using namespace std;

constexpr long long INF = 1e9;
using ll = long long;
constexpr int MXN = 500;

long long cou = 0;
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
        // cerr << "Fffff" << endl;
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
		for (int y = 1; y <= n; ++y){
			ans += g[my[y]][y];
            cerr << my[y] << ' ' << y << endl;
            if(g[my[y]][y] == 1e6) {
                cou++;
            }
        }
		return ans;
	}
} graph;

void solvv() {
	int n;
	cin >> n;
	int tmp1, tmp2, tmp3;
	graph.init(n);
	for (int i = 1; i <= n; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		graph.addEdge(i, tmp1, 1e6);
		graph.addEdge(i, tmp2, 1e3);
		graph.addEdge(i, tmp3, 10);
	}
	cout << graph.solve() << endl;
	cout << cou << endl;
    cou=0;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solvv();
	}
}
