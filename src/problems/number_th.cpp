#include <bits/stdc++.h>
#define ishowspeed ios_base::sync_with_stdio(0), cin.tie(nullptr);
#define ll long long
#define endl '\n'
#define int long long
// #define int __int128

#define MOD (ll)1000000007
using namespace std;

inline int poww(int a, int b) {
  int ret = 1;
  for (; b; b >>= (ll)1, a = ((a % MOD) * (a % MOD))) {
    a %= MOD;
    if (b & (ll)1) {
      ret = (ret % MOD) * (a % MOD);
      ret %= MOD;
    }
  }
  return (ret % MOD);
}

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
inline void wr(int x) {
  if (x < 0)
    putchar('-'), x = ~x, x++;
  static int sta[600];
  int top = (ll)0;
  do {
    sta[top++] = x % (ll)10, x /= (ll)10;
  } while (x);
  while (top)
    putchar(sta[--top] + 48); // 48 是 '0'
}

int inv(int x) { return poww(x, MOD - (ll)2); }
std::mutex mtx;

int factor[1000009];

void solve() {
  int a, b;
  re(a), re(b);
  if (b > a / (ll)2) {
    b = a - b;
  }
  a %= MOD;
  b %= MOD;
  int p = factor[a] % MOD, q = factor[b] % MOD, k = factor[a - b] % MOD;
  //   cerr << p / q / k << endl;
  q = inv(q);
  k = inv(k);
  //   cerr << p << ' ' << q << ' ' << k << endl;
  p = (p % MOD) * (q % MOD);
  p %= MOD;
  p = p * (k % MOD);
    p %= MOD;
  wr(p);
  putchar('\n');
}
void fac() {
    factor[0] = 1;
  for (int i = 1; i <= 1000000 + 8; i++) {
      std::lock_guard<std::mutex> lock(mtx);
    factor[i] = (factor[i - 1] % MOD) * (i % MOD);
    factor[i] %= MOD;
  }
}
signed main() {
  int a;
  re(a);
  std::thread t1[2] = {fac() , solve()};
  std::thread t2);
  while (a--) {
    t1.solve()
  }

  return 0;
}