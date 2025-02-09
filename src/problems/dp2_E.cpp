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
#define pb push_back
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define ishowspeed ios_base::sync_with_stdio(0), cin.tie(nullptr);
using ll = long long;
// #define ll long long
#define endl '\n'
#define lcm(a, b) (a * b) / __gcd(a, b)
#define pause printf("Press any key to continue...\n"), fgetc(stdin);
#define int long long
// #define int __int128
#define lowbit(x) (x & -x)
#define MOD 1000000009
#define cr(x) (x << 1)
#define cl(x) (x << 1) + 1
#define mmax(a, b) (a > b) ? a : b
#define mmin(a, b) (a < b) ? a : b
using namespace std;
const int N = 1e5 + 5;

int cas = 1;
vector<vector<int>> dp(300, vector<int>(300, 0));
vector<vector<int>> d(300, vector<int>(300, 0));
vector<vector<int>> r(300, vector<int>(300, 0));

void p_Median(int N, int P) {
  int m;
  vector<int> arr(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= N; ++i)
    for (int j = i; j <= N; ++j) {
      m = (i + j) / 2, d[i][j] = 0; // m是中位數，d[i][j]為距離的總和
      for (int k = i; k <= j; ++k)
        d[i][j] += abs(arr[k] - arr[m]);
    }

  for (int j = 1; j <= N; j++) {
    dp[1][j] = d[1][j];
  }

  for (int i = 1 ; i <= N; i++) {
    r[1][i] = 1;
  }
  for (int p = 2; p <= P; ++p) {
    for (int n = N; n >= 1; --n) {
      dp[p][n] = 1e9;
      for (int k = p; k <= n; ++k)
        if (dp[p - 1][k - 1] + d[k][n] < dp[p][n]) {
          dp[p][n] = dp[p - 1][k - 1] + d[k][n];
          r[p][n] = k; // 從第k個位置往右到第j個位置
        }
    }
  }
//   for (int i = 1; i <= P; i++) {
//     for (int j = 1; j <= N; j++) {
//       cerr << r[i][j] << ' ';
//     }
//     cerr << endl;
//   }
  int sum = dp[P][N];
  cout << "Chain " << cas++ << endl;
  vector<pii> ans;
  int now = r[P][N];
  int en = N;
  int cnt = P;
  while (cnt > 0) {
    ans.pb(mk(now, en));
    en = now - 1;
    now = r[--cnt][now - 1];
	
  }
  cnt = 1;
  reverse(all(ans));
  for (auto p : ans) {
    if (p.first != p.second)
      cout << "Depot " << cnt++ << " at restaurant "
           << ((p.first + p.second) >> 1) << " serves restaurants " << p.first
           << " to " << p.second << endl;
    else
      cout << "Depot " << cnt++ << " at restaurant " << p.first
           << " serves restaurant " << p.first << endl;
  }
  cout << "Total distance sum = " << sum << endl << endl;
}

signed main() {
  ishowspeed int a, b;
  while (cin >> a >> b) {
    if (a != 0 && b != 0)
      p_Median(a, b);
    else {
      return 0;
    }
  }
  return 0;
}