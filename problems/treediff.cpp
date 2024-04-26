#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define ishowspeed ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define mk make_pair
const int N = 40003;
vector<int> tag(N , 0);
vector<vector<int>> con(N);
int tim;
unordered_map<int,bool> vis;
vector<int> in(N);
vector<int> out(N);
int logN;
int n;
int root;
vector<vector<int>> anc(N , vector<int>(N , 0));
bool is_ancestor(int x , int y) { // x is y's is_ancestor 
	return (in[x] <= in[y] && out[x] >=  out[y]); 
}

int getlca(int x , int y) {
	if(is_ancestor(x , y)) return x;
	if(is_ancestor(y , x)) return y;
	for(int i = logN ; i >= 0 ; i--) {
		if(!is_ancestor(anc[x][i] , y)) {
			x = anc[x][i];
		}
	}
	return anc[x][0];
}

void make_chart() {
	for(int i = 1 ; i <= logN ; i++) 
		for(int j = 1 ; j <=  n ; j++) {
			anc[j][i] = anc[anc[j][i - 1]][i-1];
		}
}

void init(int now , int an) {
	anc[now][0] = an;
	vis[now] = 1;
	for ( auto i : con[now] ) {
		if(!vis[i])
			init(i , now);
	}
}
void t(int l) {
	vis[l] = 1;
	in[l] = tim++;
	for(auto i : con[l]) 
		if(!vis[i])
			t(i);
	out[l] = tim++;
}

void add(int x,int y){
    int lca=getlca(x,y);
    tag[x]++;
    tag[y]++;
    tag[lca]--;
    if(lca!=root)tag[anc[lca][0]]--;
}
int ans = 0;
vector<int> anx(N,0);
void dfs(int k) {
	ans += tag[k];
	anx[k] = ans;
	vis[k] = 1;
	for(auto i : con[k]) {
		if(!vis[i]) {
			dfs(i);
		}
	}
}

void solve() {
	cin >> n;
	int tmp1 , tmp2;
	int kk[n + 2] ;
	for(int i = 1 ; i <= n ; i++) 
		kk[i] = 0;
	for(int i = 0 ; i < n - 1; i++) {
		cin >> tmp1 >> tmp2;
		con[tmp1].pb(tmp2);
		con[tmp2].pb(tmp1);
		kk[tmp1]++;
		kk[tmp2]++;
	}
	int minn_index = 0x3f3f3f3f;
	for(int i = 1 ; i <= n ;i++) {
		if(minn_index > kk[i]) {
			minn_index = kk[i];
			root = i;
		}
	}
	logN = log2(n);
	t(root); 
	vis.clear();
	for(auto i : con[root]) 
		init(i , 1);
	make_chart();

	for(int i = 1; i < n ; i++) {
		add(i , i + 1) ;
	}
	vis.clear();
	dfs(root);
	for( int i = 1 ; i <= n ; i++ )
		cout << anx[i] << endl;
	return ;
}
signed main() {

    ishowspeed
    solve();
    return 0;
}
