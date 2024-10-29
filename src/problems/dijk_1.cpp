#include <bits/stdc++.h>
#define mk make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define ishowspeed ios_base::sync_with_stdio(0),cin.tie(nullptr);
#define ll long long
#define endl '\n'
#define lcm(a , b) (a * b) / __gcd(a ,b)
#define pause printf("Press any key to continue...\n") , fgetc(stdin);
#define int long long
#define si 300000
#define MXN INT64_MAX
using namespace std;

int lowbit(int x) { // 0沒有lowbit
    return (x&-x);
}
typedef struct Binary_Indexed_Tree{
    int n;
    vector<long long> bit;
    int lowbit(int x){
        return x&-x;
    }
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


inline int poww(int a , int b) {
    int ret = 1;
    for( ; b ; b >>= 1 , a *= a) {
        if(b &  1) {
            ret *= a;
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

inline int mmax(int x ,int y){
    return x > y ? x : y ;
}
inline int mmin(int x ,int y){
    return x < y?x:y;
}

bool const operator == (pair<int,int> &a , pair<int,int> &b){
    if(a.first==b.first && a.second == b.second) return true;
    else return false;
}
signed main() {
    // mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    // uniform_int_distribution<> gen(1 , 10);
    int a , n;re(a) , re(n);
    int dis[si];
    bool vis[si];memset(vis,false,sizeof(vis));
    vector<pair<int,int>> vec[si];
    for(int i=1;i<=a;i++)dis[i]=INT64_MAX-10;
    for(int i = 0 ; i < n ; i++) {
        int k , c, b;
        re(k) , re(c) , re(b);
        vec[k].pb(mk(c,b));
    }
    dis[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//以小到大排序
    pq.push({dis[1],1});

    while(pq.empty()==0){
        int u = pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto [v,w]:vec[u]){
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }    
    for(int i = 1 ; i <= a ; i++) {
        wr(dis[i]),putchar(' ');
    }
    return 0;
}