#include<bits/stdc++.h>
#include<random>
#define pii pair<int,int>
#define pb push_back
using namespace std;
signed main() {
	mt19937 now(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<> gen(1 , 10);

	uniform_int_distribution<> ge(0 , 25);
	// uniform_int_distribute<> gn(1, N);

	int n  = 8 , q = 3;
	cout << n << endl;

	for(int i = 0 ; i < n ; i++) {
		int siz = gen(now);
		string k ;
		for(int j = 0 ; j < siz ; j++ ) {
			k.pb(ge(now)+'a');
		}
		cout << k << endl;
	}
	cout << q << endl;
	for(int i = 0 ; i < q ; i++) {
		int siz2 = gen(now);
		int init = gen(now);
		for(int j = init ; j < siz2 ; j++) {
			
		}
		int siz = gen(now);
		string k;
		for(int j = 0 ; j < siz ; j++) {
			k.pb(ge(now)+'a');
		}
		cout << k << endl;
	}
}

