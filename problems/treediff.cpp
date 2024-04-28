#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define ishowspeed ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define mk make_pair
const int N = 400002;
vector<int> tag(N , 0);
vector<vector<int>> con(N);
vector<int> in(N);
vector<int> out(N);
vector<int> ans(N , 0);
int ancc[N][30];
int tim;
int timing = 1;
int logN;
int n;
int root = 1;
template<class io>
inline void re(io &x) {
    io c = getchar();int w = 0 ; x = 0;
    while(c < 48 || c > 57) w|=c==45,c=getchar();
    while(c > 47 && c < 58)x=(x<<3)+(x<<1)+(c&15),c=getchar();
    x=w?-x:x;return;
}
template <class io>
inline void wr(io x) {
  if(x==0){
    putchar('0');
    return;
  }
    if(x < 0) 
        putchar('-'), x=~x,x++;
  static int sta[300];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);  // 48 是 '0'
};
inline bool is_ancestor(int x , int y) { // x is y's is_ancestor 
	return (in[x] <= in[y] && out[x] >=  out[y]); 
}
inline int getlca(int x, int y){
    if(is_ancestor(x, y))return x; // 如果 u 為 v 的祖先則 lca 為 u
    if(is_ancestor(y, x))return y;// 如果 v 為 u 的祖先則 lca 為 u
    for(int i=logN;i>=0;i--){    // 判斷 2^logN, 2^(logN-1),...2^1, 2^0 倍祖先
        if(!is_ancestor(ancc[x][i], y)) // 如果 2^i 倍祖先不是 v 的祖先
            x = ancc[x][i];           // 則往上移動
    }
    return ancc[x][0];// 回傳此點的父節點即為答案
}

void dfs(int now , int fa) {
	ancc[now][0] = fa;	
	in[now] = timing++;
	for(auto i : con[now]) {
		if( i == fa ) continue;
			dfs(i , now);
	}
	out[now] = timing++;
}

int dfss(int now,int fa){
    int diff=tag[now];
	for(auto nxt:con[now]){
        if(nxt==fa)continue;
        diff+=dfss(nxt,now);
    }
    return ans[now]=diff;
}
inline void make_chart() {
	for(int i=1;i<=logN;i++){
 	   for(int now=1;now<=n;now++){
 	       ancc[now][i]=ancc[ancc[now][i-1]][i-1];
 	   }
	}
}
void add(int x,int y){
    int lca=getlca(x,y);
    tag[x]++;
    tag[y]++;
    tag[lca]--;
    if(lca!=root) {
		tag[ancc[lca][0]]--;
	}
}
void solve() {
	re(n);
	int tmp1 , tmp2;
	for(int i = 0 ; i < n - 1; i++) {
		re(tmp1) , re(tmp2);
		con[tmp1].pb(tmp2);
		con[tmp2].pb(tmp1);
	}
	ancc[1][0] = 1;
	logN = log2(n);
	dfs(root , 1);
	make_chart();
	for(int i = 1 ; i < n ; i++) {
		add(i , i + 1) ;
	}
	dfss(root , ancc[root][0]);
	for(int i = 1 ; i <= n ; i++) {
		wr(ans[i]);
		putchar('\n');
	}
}
signed main() {
    // ishowspeed
    solve();
    return 0;
}
