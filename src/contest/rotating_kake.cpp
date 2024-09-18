#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define ms(x, y) memset(x, y, sizeof(x))
#define SZ(x) int(x.size())
#define fk cout << "fk" << endl
#define debug(x) cerr << (#x) << '=' << (x) << endl
#define debug2(x, y)                                                           \
	cerr << (#x) << '=' << (x) << ' ' << (#y) << '=' << (y) << endl
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long i64;
template <class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template <class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
void fastio() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
}
// 1.integer overflow (1e5 * 1e5) (2e9 + 2e9)
// 2.runtime error  (divide ZERO)
// 3.boundary condition
const double eps = 1e-8;
// 如果x是正數 return 1, 如果x的數值小於eps return 0 如果x是負數 return -1
struct vec {
	double x, y;
	vec(double _x = 0, double _y = 0) { x = _x, y = _y; }
	vec operator+(vec v) { return vec(x + v.x, y + v.y); }
	vec operator-(vec v) { return vec(x - v.x, y - v.y); }
	bool operator==(vec v) { return (!sgn(x - v.x) && !sgn(y - v.y)); }
	vec operator*(double v) { return vec(x * v, y * v); }
	vec operator/(double v) { return vec(x / v, y / v); }
	bool operator<(vec b) const {
		return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : sgn(x - b.x) < 0;
	}

	double operator*(vec v) { return x * v.x + y * v.y; }

	double len() { return hypot(x, y); }
	double len_sqr() { return x * x + y * y; }

	//逆时针旋转
	vec rot(double c) {
		return vec(x * cos(c) - y * sin(c), x * sin(c) + y * cos(c));
	}
	vec trunc(double l) { return (*this) * l / len(); }
	vec rot90() { return vec(-y, x); }
} v[2 * (int)1e5 + 100], tu[2 * (int)1e5 + 100];
int sgn(double x) {
	if (fabs(x) < eps)
		return 0;
	if (x < 0)
		return -1;
	return 1;
}
//外積
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
bool cmpXY(vec a, vec b) {
	if (sgn(a.x - b.x))
		return a.x < b.x;
	return a.y < b.y;
}
int convex_hull(vec *v, int n, vec *z) {
	sort(v, v + n, cmpXY);
	int m = 0;
	for (int i = 0; i < n; ++i) {
		while (m > 1 && cross(z[m - 1] - z[m - 2], v[i] - z[m - 2]) <= 0)
			--m;
		z[m++] = v[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; --i) {
		while (m > k && cross(z[m - 1] - z[m - 2], v[i] - z[m - 2]) <= 0)
			--m;
		z[m++] = v[i];
	}
	if (n > 1)
		--m;
	return m;
}
long double kake(vec *v, int v_len) { //旋转卡壳
	long double ans = 1e15;
	int idx = 1;
	v[v_len] = v[0];
	for (int i = 0; i < v_len; ++i) {
		while (fabs(cross(v[i + 1] - v[i], v[idx + 1] - v[i])) >
			   fabs(cross(v[i + 1] - v[i], v[idx] - v[i]))) {
			if (idx >= v_len)
				idx -= v_len;
			else
				idx += 1;
		}
		long double now = fabs(cross(v[i + 1] - v[i], v[idx] - v[i])) /
					 (v[i] - v[i + 1]).len();
		if (sgn(now - ans) == -1)
			ans = now;
	}
	printf("%.16f\n", ans);
	// return ans;
}
int main() {
	fastio();
	int n, r;
	// fk;
	scanf("%d%d", &n, &r);
	forn(i, n) { scanf("%lf%lf", &v[i].x, &v[i].y); }
	int tu_len = convex_hull(v, n, tu);
	kake(tu, tu_len);
	return 0;
}