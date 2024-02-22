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
#define pii pair<int,int> 
#define all(x) (x).begin(),(x).end()
#define ishowspeed ios_base::sync_with_stdio(0),cin.tie(nullptr);
#define ll long long
#define endl '\n'
#define lcm(a , b) (a * b) / __gcd(a ,b)
#define pause printf("Press any key to continue...\n") , fgetc(stdin);
#define int long long
#define lowbit(x) (x&-x)
// #define MOD 998244353
#define MXN 400'500
#define cr(x) (x<<1)
#define cl(x) (x<<1)+1
#define mmax(a,b) (a > b)?a:b
#define mmin(a,b) (a<b)?a:b
using namespace std;
const int N=1e5+5;
#define LOCAL
#ifdef LOCAL    // =========== Local ===========
void dbg() { cerr << '\n'; }
template<class T, class ...U> void dbg(T a, U ...b) { cerr << a << ' ', dbg(b...); } 
template<class T> void org(T l, T r) { while (l != r) cerr << *l++ << ' '; cerr << '\n'; } 
#define debug(args...) (dbg("#> (" + string(#args) + ") = (", args, ")"))
#define orange(args...) (cerr << "#> [" + string(#args) + ") = ", org(args))
#else            // ======== OnlineJudge ========
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif
const int MOD = 1000000009;
int pre[MXN];
int rea[MXN];
/*
inline void pull(int id) {
    seg[id] = mmax(seg[cl(id)] , seg[cr(id)]);
}
void build(int id , int l , int r) {
    if(l==r){
        seg[id]=arr[l];
        return ;
    }
    else {
        int mid=(l+r)/2;
        build( cl(id) , l , mid);
        build( cr(id) , mid+1, r);
        pull(id);
    }
}
void update(int id , int l , int r , int x , int v){
    if(l==r){
        seg[id]=v;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid){
        update(cl(id) , l , mid ,x , v);
    }
    if(mid<x){
        update(cr(id) , mid+1,r,x,v);
    }
    pull(id);
}
int query(int id,int l,int r,int sl,int sr){
    if(sl<=l&&r<=sr){//目前這個區間在查詢區間內
        return seg[id];
    }
    int mid=(l+r)>>1,res=0;
    if(sl<=mid){//左區間跟查詢區間有交集
        res=mmax(res,query(cl(id),l,mid,sl,sr));
    }
    if(mid<sr){//右區間跟查詢區間有交集
        res=mmax(res,query(cr(id),mid+1,r,sl,sr));
    }
    return res;
}

struct Binary_Indexed_Tree{
    int n;
    vector<long long> bit;

    void init(int _n){
        n = _n+1;
        bit = vector<long long>(n,0);
    }
    void update(int x,int v){
        for(; x<n; x+=lowbit(x)){
            bit[x] += v;
        }
    }
    long long query(int x){
        long long ret = 0;
        for(; x>0; x-=lowbit(x)){
            ret += bit[x];
        }
        return ret;
    }
}BIT;
*/

inline int poww(int a , int b) {
    int ret = 1;
    for( ; b ; b >>= 1 , a = (a%MOD) * (a % MOD) %MOD ) {
        if(b &  1) {
            ret *= a;
            ret%=MOD;
        }

    }
    return ret;
}

template<class io>
inline void re(io &x) {
    io c = getchar();int w = 0 ; x = 0;
    while(c < 48 || c > 57) w|=c==45,c=getchar();
    while(c > 47 && c < 58)x=(x<<3)+(x<<1)+(c&15),c=getchar();
    x=w?-x:x;return;
}
inline void wr(int x) {
    if(x < 0) 
        putchar('-'), x=~x,x++;
  static int sta[300];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}

ll inv(ll x){
	return poww(x, MOD-2);
}
bool const operator == (pair<int,int> &a , pair<int,int> &b){
    if(a.first==b.first && a.second == b.second) return true;
    else return false;
}
signed main() {
    // mt19937 mt(hash<string>(":poop:"));
    // uniform_int_distribution<> gen(1 , 10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int a;
    re(a);
    int sum = 0;
    string tmp1, tmp2;
    int k = 1;
    for(int i = 0 ; i < a ; i++) {
        cin >> tmp1 >> tmp2;
        k=1;
        int cnt = 0;
        for(int j = tmp1.length()-1 ; j>=0 ; j--){
            if(tmp1[j]=='.') j-- , cnt = i;
            rea[i]+=(int)(tmp1[j]-'0') * k;
            pre[i]+=(int)(tmp2[j]-'0') * k;
            k*=10;
        }
        sum += abs((int)rea[i] - (int)pre[i]);
    }
    sum/=10;
    int sum2 = 0;
    int now = 0 , now2 = 0;
    int ans = 1 , ans2 = 0;
    int tmp = sum;
    int cnt = 0;
    cerr << sum << endl;
    while(tmp) {
        cnt++;
        tmp/=10;
    }
    int cnt2 = 0;
    for(int i = 5 ; i > 0 ; i--) {
        sum2 = 0;
        cnt2 = 0;
        for(int j = 0 ; j < a ; j++) {
            now = (int)pre[j]/poww(10,i);
            now = now*poww(10,i);
            now2 = (int)rea[j]/poww(10,i);
            now2 = now2*poww(10,i);
            sum2+=abs(now2 - now);
        }
        tmp = sum2;
        while(tmp) {
            cnt2++;
            tmp/=10;
        }
        if(cnt - cnt2 > 0)
            sum2 *= poww(10 , cnt - cnt2);
        else {
            sum2 /= poww(10 , cnt2 - cnt);
        }
        if(sum2 == sum) {
            ans = i;
            ans2=sum;
            break;
        }
        ans2 = sum2;
    }
    cerr << "ans2 = " << ans2 << endl;
    ans2 /= poww(10 ,3);
    double ans22 = ans2;
    ans22/=10;
    cout << ans << ' ' << setprecision(5) << fixed << ans22 << endl;
    return 0;
}