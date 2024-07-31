#include<bits/stdc++.h>
#include<random>
#define pii pair<int,int>
#define pb push_back
using namespace std;
signed main() {
	mt19937 now(chrono::steady_clock::now().time_since_epoch().count());

	// uniform_int_distribution<> ge(0 , 25);
	// uniform_int_distribute<> gn(1, N);

	int n = 4 , m = 4;
	cout << n << ' ' << m << endl;
	uniform_int_distribution<> gen(1 , n);
	for(int i = 0 ; i < m ; i++) {
		int a, b, c;
		a=gen(now);
		b=gen(now);
		c=gen(now);
		while(a == b) {
			a = gen(now);
		}
		cout << a << ' ' << b << ' ' << c << endl; 
	}
}

