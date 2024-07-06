// #pragma GCC optimize(1)
// #pragma GCC optimize(2)
// #pragma GCC optimize(3)
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("-falign-jumps")
// #pragma GCC optimize("-falign-loops")
// #pragma GCC optimize("-falign-labels")
// #pragma GCC optimize("-fdevirtualize")
// #pragma GCC optimize("-fcaller-saves")
// #pragma GCC optimize("-fcrossjumping")
// #pragma GCC optimize("-fthread-jumps")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-fwhole-program")
// #pragma GCC optimize("-freorder-blocks")
// #pragma GCC optimize("-fschedule-insns")
// #pragma GCC optimize("inline-functions")
// #pragma GCC optimize("-ftree-tail-merge")
// #pragma GCC optimize("-fschedule-insns2")
// #pragma GCC optimize("-fstrict-aliasing")
// #pragma GCC optimize("-fstrict-overflow")
// #pragma GCC optimize("-falign-functions")
// #pragma GCC optimize("-fcse-skip-blocks")
// #pragma GCC optimize("-fcse-follow-jumps")
// #pragma GCC optimize("-fsched-interblock")
// #pragma GCC optimize("-fpartial-inlining")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("-freorder-functions")
// #pragma GCC optimize("-findirect-inlining")
// #pragma GCC optimize("-frerun-cse-after-loop")
// #pragma GCC optimize("inline-small-functions")
// #pragma GCC optimize("-finline-small-functions")
// #pragma GCC optimize("-ftree-switch-conversion")
// #pragma GCC optimize("-foptimize-sibling-calls")
// #pragma GCC optimize("-fexpensive-optimizations")
// #pragma GCC optimize("-funsafe-loop-optimizations")
// #pragma GCC optimize("inline-functions-called-once")
// #pragma GCC optimize("-fdelete-null-pointer-checks")

#include <bits/stdc++.h>
#define mk make_pair
#define pb push_back
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define ishowspeed ios_base::sync_with_stdio(0), cin.tie(nullptr);
#define ll long long
#define endl '\n'
#define lcm(a, b) (a * b) / __gcd(a, b)
#define pause printf("Press any key to continue...\n"), fgetc(stdin);
#define int long long
// #define int __int128
#define lowbit(x) (x & -x)
#define MOD 998244353
#define MXN 400'500
#define cr(x) (x << 1)
#define cl(x) (x << 1) + 1
#define mmax(a, b) (a > b) ? a : b
#define mmin(a, b) (a < b) ? a : b
using namespace std;
const int N = 1e5 + 5;
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
int arr[N] = {};
// int seg[N*4];
// inline void pull(int id) {
//     seg[id] = mmax(seg[cl(id)] , seg[cr(id)]);
// }
// void build(int id , int l , int r) {
//     if(l==r){
//         seg[id]=arr[l];
//         return ;
//     }
//     else {
//         int mid=(l+r)/2;
//         build( cl(id) , l , mid);
//         build( cr(id) , mid+1, r);
//         pull(id);
//     }
// }
// void update(int id , int l , int r , int x , int v){
//     if(l==r){
//         seg[id]=v;
//         return;
//     }
//     int mid=(l+r)>>1;
//     if(x<=mid){
//         update(cl(id) , l , mid ,x , v);
//     }
//     if(mid<x){
//         update(cr(id) , mid+1,r,x,v);
//     }
//     pull(id);
// }
// int query(int id,int l,int r,int sl,int sr){
//     if(sl<=l&&r<=sr){//目前這個區間在查詢區間內
//         return seg[id];
//     }
//     int mid=(l+r)>>1,res=0;
//     if(sl<=mid){//左區間跟查詢區間有交集
//         res=mmax(res,query(cl(id),l,mid,sl,sr));
//     }
//     if(mid<sr){//右區間跟查詢區間有交集
//         res=mmax(res,query(cr(id),mid+1,r,sl,sr));
//     }
//     return res;
// }

// struct Binary_Indexed_Tree{
//     int n;
//     vector<long long> bit;

//     void init(int _n){
//         n = _n+1;
//         bit = vector<long long>(n,0);
//     }
//     void update(int x,int v){
//         for(; x<n; x+=lowbit(x)){
//             bit[x] += v;
//         }
//     }
//     long long query(int x){
//         long long ret = 0;
//         for(; x>0; x-=lowbit(x)){
//             ret += bit[x];
//         }
//         return ret;
//     }
// }BIT;

// inline int poww(int a , int b) {
//     int ret = 1;
//     for( ; b ; b >>= 1 , a *= a) {
//         if(b &  1) {
//             ret *= a;
//         }
//     }
//     return ret;
// }

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

// ll inv(ll x){
// 	return poww(x, MOD-2);
// }
// bool const operator == (pair<int,int> &a , pair<int,int> &b){
//     if(a.first==b.first && a.second == b.second) return true;
//     else return false;
// }

int V;
void solve() {
  int n, m, k;
  re(n);
  re(m);
  re(k);
  vector<int> dp(n + 5, -1);
  for (int i = 1; i <= n; i++) {
    re(arr[i]);
    dp[i] = -1;
  }
  dp[0] = 0;
  int cnt = 0;
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    int now = 0;
    int maxx = arr[i];
    int minn = arr[i];
    int j = i;
    while (j > 0) {
      now++;
      maxx = mmax(maxx, arr[j]);
      minn = mmin(minn, arr[j]);
      if (now >= m && (maxx - minn) <= k && dp[j - 1] >= 0) {
        dp[i] = j;
        break;
      }
      j--;
    }
  }
  for (int i = n; i > 0; i--) {
    int sum = 0;
    while (dp[i] > 0 && sum < m) {
      sum += i - dp[i] + 1;
      i = dp[i];
    }
    // cerr << sum << endl;
    if (sum >= m) {
      ans.pb(sum);
      cnt++;
    } else {
      goto eat_shit;
    }
  }
  if (cnt <= 1) {
    goto eat_shit;
  }
  reverse(ans.begin(), ans.end());
  wr(cnt);
  putchar('\n');
  for (auto I : ans) {
    wr(I);
    putchar(' ');
  }
  return;

eat_shit:
  putchar('-');
  putchar('1');
  return;
}

signed main() {
  // mt19937 mt(hash<string>(":poop:"));
  // uniform_int_distribution<> gen(1 , 10);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  solve();

  return 0;
}