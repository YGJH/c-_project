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
#define mk make_pair
#define lowbit(x) (x & -x)
#define pb push_back
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define ishowspeed ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(0);
using ll = long long;
#define endl '\n'
#define lcm(a, b) ((a) * (b)) / __gcd(a, b)
#define int long long
// #define int __int128
#define cr(x) (x << 1)
#define cl(x) (x << 1) | 1
#define mmax(a, b) (a > b) ? a : b
#define mmin(a, b) (a < b) ? a : b
using namespace std;
const int MOD = (ll)1e9 + 7;
#define LOCAL
#ifdef LOCAL // =========== Local ===========
void dbg() { cerr << '\n'; }
template <class T, class... U> void dbg(T a, U... b) {
  cerr << a << ' ', dbg(b...);
}
template <class T> void org(T l, T r) {
  while (l != r)
    cerr << *l++ << ' ';
  cerr << '\n';
}
#define debug(args...) (dbg("#> (" + string(#args) + ") = (", args, ")"))
#define orange(args...) (cerr << "#> [" + string(#args) + ") = ", org(args))
#else // ======== OnlineJudge ========
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif
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
  if (x == 0) {
    putchar('0');
    return;
  }
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
vector<int> factor(2000, 0);
int fac(int n) {
  if (n == 1)
    return (factor[1] = 1);
  return factor[n] = (fac(n - 1) * n) % MOD;
}
namespace mypow {
inline int pow(int i, int l) {
  int ret = 1;
  for (; l; l >>= 1, i = (i * i) % MOD) {
    if (l & 1) {
      ret = (ret * i) % MOD;
    }
  }
  return ret;
}
} // namespace mypow
inline int inv(int n) { return mypow::pow(n, MOD - 2); }
inline int cFun(int n, int m) {
  //  n!  / m! / (n - m)!
  if (n == m || m == 0) {
    return 1;
  }
  int k = factor[n];
  int tmp = inv(factor[m]);
  int tmp2 = inv(factor[n - m]);
  return (((k * tmp) % MOD) * tmp2) % MOD;
}
inline int countDigit(int n) {
  int ret = 0;
  while (n) {
    ret++;
    n = n ^ lowbit(n);
  }
  return ret;
}
int c_countDig(string s) {
  int ret = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '1') {
      ret++;
    }
  }
  return ret;
}
void solve() {
  string dig;
  cin >> dig;
  int k;
  cin >> k;
  vector<int> dp(2000);
  vector<int> parent(2000);
  vector<int> siz(2000, 0);
  dp[1] = 1;
  parent[1] = 0;
  siz[1] = 0;
  const int len = dig.length();
  int one_bit = c_countDig(dig);
  int ze_bit = len - one_bit;
  if (len == 1) {
    if (k >= 1)
      cout << 0 << endl;
    else
      cout << 1 << endl;
    return;
  }
  vector<int> dec(2000, 0);
  for (int i = 2; i <= len; i++) {
    int tmp = i;
    for (int j = 0; j < len; j++) {
      if (dig[j] == '1') {
        tmp--;
        if (tmp == 0) {
          break;
        }
      } else if (dig[j] == '0') {
        dec[i] += cFun(len - j - 1, tmp);
        if (dec[i] >= 1) {
          dec[i]--;
        }
      }
    }
  }
  for (int i = 1; i <= len; i++) {
    dp[i] = cFun(len, i);
    parent[i] = countDigit(i);
    siz[i] = siz[parent[i]] + 1;
  }
  dp[1]--;
  // cerr << "siz: ";
  // for(int i = 1 ; i <= len ; i++) {
  //   cerr << siz[i] << ' ';
  // }
  // cerr << endl << "parent: ";
  // for(int i = 1 ; i <= len ; i++) {
  //   cerr << parent[i]  << ' ';
  // }
  // cerr << endl << "dp: ";
  // for(int i = 1 ; i <= len ; i++) {
  //   cerr << dp[i] << ' ';
  // }
  for(int i = 1 ; i <= len ; i++) {
    cerr << dec[i] << ';';
  }
  int ans = 0;
  for (int i = 1; i < len; i++) {
    if (siz[i] == k) {
      ans += dp[i];
      ans %= MOD;
      // cerr << dec[i] << ';';
      ans -= dec[i];
    }
  }

  cout << ans << endl;
}

signed main() {
  // mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  // mt19937 mt(hash<string>(":poop:"));
  // uniform_int_distribution<> gen(1 , 10);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ishowspeed factor[0] = 0;
  fac(1000);
  solve();
  return 0;
}