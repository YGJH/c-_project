#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MAXN = 1e3+5 , MOD = 1e9 + 7 , N = 1e3;
ll fac[MAXN] , inv[MAXN];
ll dp[MAXN];

ll fpow(ll a , ll b) {
	ll ret =1 ;
	for( ; b ; b >>=1  , a = (a*a) % MOD) {
		if(b & 1) {
			ret *= a;
			ret %= MOD;
		}
	}

	return ret;
}
void init() {
	fac[0] = inv[0] = 1;
	for(ll i = 1 ; i <= N ; i++) 
		fac[i] = (fac[i-1] * i) % MOD;
	inv[N] = fpow(fac[N] , MOD - 2) ;
	for(ll i = N -1 ; i >= 0 ; i--)
		inv[i] = (inv[i+1] * (i + 1)) % MOD;

	for(ll i =2 ; i <= N ; i++)
		dp[i] = dp[__builtin_popcount(i)] + 1;

}
ll comb(ll n , ll k) {
	if( n < k ) 
		return 0;
	return fac[n] * ( inv[k] * inv[n-k] % MOD ) % MOD;

}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();
	string s;
	ll k;
	cin >> s >> k;
	if(!k) 
		cout << "1\n";
	else {
		ll len = s.length() , num = 0;
		ll ans = 0;
		for(ll i = 0 ; i < len ; i++) {
			if(s[i] == '0') 
				continue;
			for(ll j = max(num , (ll)1) ; j < len ; j++) {
				if( dp[j] == k-1) {
					ans = (ans + comb( len - i - 1 , j - num)) % MOD;
				}
			}
			num++;
		}
		if( k == 1 ) 
			ans = (ans - 1 + MOD) % MOD;
		if(dp[num] == k - 1)
			ans = (ans + 1 ) % MOD;
		cout << ans << endl;
	}
	return 0;
}


