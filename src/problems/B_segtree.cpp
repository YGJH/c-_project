#include <bits/stdc++.h>
#define mk make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define ishowspeed ios_base::sync_with_stdio(0),cin.tie(nullptr);
#define ll long long
#define endl '\n'
#define lcm(a , b) (a * b) / __gcd(a ,b)
#define pause printf("Press any key to continue...\n") , fgetc(stdin);
// #define int long long
#define lowbit(x) (x&-x)
#define MOD 998244353
#define MXN 200005
#define cr(x) (x<<1)
#define cl(x) (x<<1)+1
#define mmax(a,b) (a > b)?a:b
#define mmin(a,b) (a<b)?a:b

using namespace std;
int arr[MXN];
int seg[MXN*4];
void pull(int id){
    seg[id]=seg[cl(id)]^seg[cr(id)];
}
void build(int id,int l,int r){
    if(l==r){
        seg[id]=arr[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(cl(id),l,mid);
    build(cr(id),mid+1,r);
    pull(id);
}
void update(int id,int l,int r,int x,int v){
    if(l==r){
        seg[id]=v;
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid){
        update(cl(id),l,mid,x,v);    
    }
    if(mid<x){
        update(cr(id),mid+1,r,x,v);  
    }
    pull(id);
}
int query(int id,int l,int r,int sl,int sr){
    if(sl<=l&&r<=sr){//目前這個區間在查詢區間內
        return seg[id];
    }
    int mid=(l+r)>>1,res1=INT32_MAX ,res2 = INT32_MAX;
    if(sl<=mid){//左區間跟查詢區間有交集
        res1=query(cl(id),l,mid,sl,sr);
    }
    if(mid<sr){//右區間跟查詢區間有交集
        res2=query(cr(id),mid+1,r,sl,sr);
    }
    return res1^res2;
}

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

// ll inv(ll x){
// 	return poww(x, MOD-2);
// }
// bool const operator == (pair<int,int> &a , pair<int,int> &b){
//     if(a.first==b.first && a.second == b.second) return true;
//     else return false;
// }

signed main() {
    // mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    // uniform_int_distribution<> gen(1 , 10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n , m , command , st , en ; re(n) , re(m);
    for(int i = 1 ; i <= n ; i++) re(arr[i]);
    build(1 , 1 , n);
    for(int i = 1 ; i <= m ; i++) {
        re(command) , re(st) , re(en);
        if(command == 1) {
            update(1 , 1 , n , st , en);
        }//update k to u
        else {
            wr(query(1, 1 , n , st , en)), putchar('\n');
        }// query [a , b]
    }
    return 0;
}