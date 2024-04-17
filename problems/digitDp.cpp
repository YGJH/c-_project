#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define mk make_pair
#define pb push_back
#define ishowspeed ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(0);
using ll = long long;
#define endl '\n'
#define int long long
#define lowbit(x) (x&-x)
using namespace std;
const int MOD = (ll)1e9 + 7;

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
vector<int> pr(1001);
vector<int> siz(1001);
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
void solve1() {
  siz[1] = 0;
  for (int i = 2 ; i <= 1000 ; i++) {
    pr[i] = countDigit(i);
    siz[i] = siz[pr[i]] + 1;
  }
}
vector<vector<vector<int>>> dp(2000 , vector<vector<int>>(2000 , vector<int>(3,0)));
unordered_map<int , bool> mp;
int ans = 0;

void solve(){
  string s;
  cin >> s;
  int a;
  cin >> a;
  s.pb('0');
  reverse(all(s));
  int len = s.length();
  cerr << s << endl;
  if(s[1]=='0') {
    dp[1][0][0]=1;
  }
  else {
    dp[1][0][0]=1;
    dp[1][1][1]=1;
  }
  for(int i = 2 ; i < len ; i++) {
    if(s[i] == '0') {
      for(int j = 0 ; j < i ; j++) {
        dp[i][j][0]+=dp[i-1][j][1];
        dp[i][j][0]+=dp[i-1][j][0];
      }
    }
    else {
      for(int j = 0 ; j < i ; j++) {
        dp[i][j][0] += dp[i-1][j][1];
        dp[i][j+1][1] += dp[i-1][j][1];
        dp[i][j+1][1] += dp[i-1][j][0];
        dp[i][j][0] += dp[i-1][j][0];
      }
    }
  }
    for(int j = 1 ; j < len ; j++) {
      if(siz[j] == a) {
        for(int i = 1 ; i <= j ; i++) {
          ans+=dp[len - 1][j][0];
          ans+=dp[len - 1][j][1];
        }
      }
    }




  cout << ans << endl;
  return;
}

signed main() {
  ishowspeed factor[0] = 0;
  fac(1000);
  siz[0] = 0;
  solve1();
  solve();
  return 0;
}