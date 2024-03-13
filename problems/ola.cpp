#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
#define eb emplace_back
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define ishowspeed ios_base::sync_with_stdio(0),cin.tie(nullptr);
using ll = long long;
// #define ll long long
#define endl '\n'
#define lcm(a , b) (((a) * (b)) / __gcd(a ,b))
#define pause printf("Press any key to continue...\n") , fgetc(stdin);
#define int long long
// #define int __int128
#define lowbit(x) (x&-x)
#define MOD 1000000009
#define MXN 400'500
#define cr(x) (x<<1)
#define cl(x) (x<<1)+1
#define mmax(a,b) (a > b)?a:b
#define mmin(a,b) (a<b)?a:b
using namespace std;
const int N=1e5+5;

pii last;
int xx[] = {-1 , 0 , 1};
vector<vector<int>> arr(N, vector<int> (5 , 0));
int ans = INT32_MAX;
int n;
void dfs(int now ,int y , int x) {
	int tmp = INT32_MAX;
	cerr << now << ' ' << y << ' ' << x << endl;
	if(y == n - 1) {
		ans = now + arr[y+1][2];
		return;
	}
	else {
		int tar = 1;
		int cnt = 0;
		for(int i = 0 ; i < 3; i++) {
			int k = x + xx[i];
			if(k <= 3 && k > 0) {
				if(tmp > arr[y+1][k]) {
					tmp = arr[y+1][k];
					tar = k;
					cnt = 0;
				}
				else if(tmp == arr[y+1][k] && k == 2) {
					tar = k;
					cnt = 0;
				}
			}
			else if( k > 3 ) {
				// cerr << tmp << endl;
				// int now2 = now;
				// int tmp2 = tmp;
				int cnt = arr[y][x];
				if(now - arr[y][x] + arr[y][2] + arr[y+1][1] < tmp + now) {
					cerr << "kkkkk" << endl;
					now = now - arr[y][x] + arr[y][2];
					tmp = arr[y+1][1];
					cnt = arr[y][2];
					tar = 1;
				}
				if(now - cnt + arr[y][1] + arr[y+1][1] < tmp + now && last.second <= 2) {
					cerr << "aaaaa" << endl;
					now = now - cnt + arr[y][1];
					tmp = arr[y+1][1];
					tar = 1;
				}
			}
		}
		if(x == 1) {
			int cnt = arr[y][x];
				if(now - arr[y][x] + arr[y][2] + arr[y+1][3] < tmp + now) {
					// cerr << "aaaaa" << endl;
					now = now - arr[y][x] + arr[y][2];
					tmp = arr[y+1][3];
					cnt = arr[y][2];
					tar = 3;
				}
				// cerr << now << ' ' << tmp << endl;
				if(now - cnt + arr[y][3] + arr[y+1][3] < tmp + now && last.second >= 2) {
					// cerr << "fefefe" << endl;
					now = now - cnt + arr[y][3];
					tmp = arr[y+1][3];
					tar = 3;
				}
		}
		last.first = y ; last.second = x;
		dfs(now + arr[y+1][tar] , y + 1 , tar);
	}
}
int cas = 1;
void solve() {
	ans = INT32_MAX;
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(arr[1][2], 1 ,2);

	// cerr << ans << endl;
	cout << cas++ << ". " << ans << endl;
}

signed main() {
    // mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    // mt19937 mt(hash<string>(":poop:"));
    // uniform_int_distribution<> gen(1 , 10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ishowspeed
	while(cin >> n) {
		if(n == 0) {
			// cerr << "exiting\n";
			return 0;
		}
		solve();
		// cerr << "OUT solve()\n";
	}
    return 0;
}