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
#define lowbit(x) (x&-x)
#define MOD 998244353
#define MXN 400'500


using namespace std;

typedef struct Binary_Indexed_Tree{
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

ll inv(ll x){
	return poww(x, MOD-2);
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

typedef struct {
    int a, b, c ,d;
}NODE;

signed main() {
    // mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    // uniform_int_distribution<> gen(1 , 10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n , m;
    re(n) , re(m);

    NODE node[n];
    pair<int,int> dis[n+2];// 以1為出發點    
    for(int i = 1 ; i <= m ; i++) {
        re(node[i].a) , re(node[i].b) , re(node[i].c);
        node[i].d = i;
    }
    dis[1].first = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//以小到大排序
    pq.push({dis[1].first,0});
    unordered_map<int,int> vis;
    while(!pq.empty() ){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i = 1 ; i <= m ; i++){
            if(node[i].a==u)
	            if(dis[u].first+node[i].c<dis[node[i].b].first){//鬆弛
                    dis[node[i].b].first=dis[u].first+node[i].c;
                    dis[node[i].b].second=node[i].d;
                    pq.push(mk(dis[node[i].b].first , node[i].b));
                }
        }
    }
    vis.clear();
    for(int i = 1 ; i <= n ; i++) {
        if(!vis[dis[i].second])
            wr(dis[i].second),  putchar(' ') , vis[dis[i].second]++;
    }

    return 0;
}