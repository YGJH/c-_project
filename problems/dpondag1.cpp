#include <bits/stdc++.h>
#define ishowspeed ios_base::sync_with_stdio(0),cin.tie(nullptr);
using ll = long long;
#define endl '\n'
#define int long long
#define MOD 1000000009
#define mmin(a,b) (a<b)?a:b
using namespace std;
const int N=1e5+5;
long long xx[] = {-1 , 0 , 1 };
int cas = 1;
int n;
vector<vector<int>> dp(N, vector<int> (5,0));
vector<vector<int>> arr(N, vector<int> (5,0));

void solve(int n) {
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= 3 ; j++) {
			cin >> arr[i][j];
		}
	}
	int a = arr[1][2] + arr[2][1], b = arr[1][2] + arr[2][2] , c = arr[1][2] + arr[2][3];
	arr[2][1] = a;
	b = mmin(b , arr[1][2] + arr[2][2] + arr[1][3]);
	b = mmin(b , arr[2][1] + arr[2][2] );
	c = mmin(c , arr[1][3] + arr[1][2] + arr[2][3]);
	c = mmin(c , b + arr[2][3]);
	arr[2][2] = b ; arr[2][3] = c;
	for(int i = 3 ; i <= n  ; i++) {
		a = mmin ( a + arr[i][1] , b + arr[i][1]);
		arr[i][1] = a;
		b = mmin ( b + arr[i][2] , arr[i-1][1] + arr[i][2]);
		b = mmin( b , arr[i][1] + arr[i][2]);
		b = mmin ( b , arr[i-1][3] + arr[i][2]);
		arr[i][2] = b;
		c = mmin( c + arr[i][3] , arr[i-1][2] + arr[i][3]);
		c = mmin( c , b + arr[i][3]);
		// c = mmin( c , b);
		// c = mmin( c , arr[i-1][1] + arr[i6][2] + arr[i][2] + arr[i][3])'';
		// c = mmin( c , arr[i-1][2] + arr[i][2] + arr[i][3]);
		arr[i][3] = c;
	}
	// for(int i = 1 ; i <= n ; i++) {
	// 	for(int j = 1; j <= 3 ; j++) {
	// 		cout << arr[i][j] << ' ';
	// 	}	
	// 	cout << endl;
	// }
	cout << cas++ << ". " << arr[n][2] << endl;
}
signed main() {

    ishowspeed
	while(cin >> n) {
		if(n == 0) {
			return 0;
		}
		solve(n);
	}
    return 0;
}