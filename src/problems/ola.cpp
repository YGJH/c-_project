#include <bits/stdc++.h>
#define mk make_pair
#define pii pair<int, int>
#define pb push_back
#define ishowspeed ios_base::sync_with_stdio(0), cin.tie(nullptr);
    using ll = long long;
#define endl '\n'
#define int long long
using namespace std;

template <class io> inline void re(io &x) {
  io c = getchar();
  int w = 0;
  x = 0;
  while (c < 48 || c > 57)
    w |= c == 45, c = getchar();
  while (c > 47 && c < 58)
    x = (x << 3) + (x << 1) + (c & 15), c = getchar();
  x = w ? -x : x;
  return;
}
template <class io> inline void wr(io x) {
  if (x < 0)
    putchar('-'), x = ~x, x++;
  static int sta[300];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top)
    putchar(sta[--top] + 48); // 48 是 '0'
}
int n, m;
vector<int> route;
vector<vector<int>> cross(200010);
vector<int> in(200010, 0);
map<pii, bool> mp;
int cnt = 0;
int tmp1, tmp2;
void dfs(int now) {
  in[now]++;
  while (cross[now].size()) {
    // cerr << "fewfe" << endl;
    auto u = cross[now].back();
    cross[now].pop_back();
    if (!mp[{now, u}]) {
      in[now]++;
      mp[{now, u}] = 1;
      mp[{u, now}] = 1;
      cnt++;
      dfs(u);
    }
  }
  route.pb(now);
  return;
}
void solve() {
  re(n);
  re(m);
  for (int i = 1; i <= m; i++) {
    re(tmp1);
    re(tmp2);
    cross[tmp1].pb(tmp2);
    cross[tmp2].pb(tmp1);
  }
  bool sam = 0;
  in[1] += 1;
  dfs(1);
  for (int i = 1; i <= n; i++) {
    // cerr << in[i] << endl;
    if (in[i] & 1) {
      sam = 1;
      break;
    }
  }
  if (sam || cnt != m) {
    putchar('I');
    putchar('M');
    putchar('P');
    putchar('O');
    putchar('S');
    putchar('S');
    putchar('I');
    putchar('B');
    putchar('L');
    putchar('E');
    return;
  } else {
    for (auto i : route) {
      wr(i);
      putchar(' ');
    }
  }
}

signed main() {
  solve();
  return 0;
}
