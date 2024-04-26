#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ishowspeed ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_bakc
#define mk make_pair
#define pii pair<int,int>

inline void pr(stack<pii> p){
	cerr << "st: ";
	while(!p.empty()) {
		cerr << p.top().first << ' ' << p.top().second << endl;
		p.pop();
	}
	cerr << endl;
}
void solve() {
	int n;
	cin >> n;
	int arr[n+3];
	for(int i = 1 ; i <= n ; i++) 
		cin >> arr[i];
	
	int ans = 0;
	stack<pii> st;
	for(int i = 1 ; i <= n ;i++) {
		while( !st.empty() && st.top().first <= arr[i]) {
			ans += i - st.top().second - 1;
			st.pop();
		}
		// cerr << "ans: " << ans << endl;
		if( st.empty() || (!st.empty() && st.top().first > arr[i]) )
			st.push(mk(arr[i] , i));
		else if(!st.empty() && st.top().first == arr[i]) 
		{
			st.top().second = i;
		}
		// pr(st);
	}
	while(!st.empty()) {
			ans += n + 1 - st.top().second - 1;
			st.pop();
	}
	cout << ans << endl;
}


signed main() {
	ishowspeed

	solve();
	return 0;
}

