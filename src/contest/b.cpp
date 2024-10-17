#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	long double a , b , c;
	cin >> a >> b >> c;
	if(c==0) {
		cout << 90 << endl;
		return 0;
	}
	long double ans;
	long double tmp = (c*2) / (a * b);
	if(tmp > a) {
		long double he = (c) / (a * a);
		long double x = b - he;
		long double kk = sqrt(a * a + (2 * x) * (2 * x));
		ans = acos((2*x) / kk);
	}
	else {
		long double x = sqrt(tmp * tmp + b * b);
		ans = acos(b / x);
	}
	ans *= (long double)(180) / (long double)(acos(-1));
	// cout << tmp << endl;
	cout << setprecision(10) << fixed << (long double)90 - ans << endl;
}