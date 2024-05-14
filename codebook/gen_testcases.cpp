#include<bits/stdc++.h>
#include<random>
#define pii pair<int,int>
#define pb push_back
using namespace std;
signed main() {
	const int N = 10;
	const int Q = 5;
	cout << N << ' ' << Q << endl;
	mt19937 now(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<> gen(1 , N);
	// uniform_int_distribute<> gn(1, N);
	for(int i = 1 ; i <= N ; i++) {
		cout << gen(now) << " \n"[i == N];
	}
	for(int i = 1 ; i <= Q ; i++) {
		int tmp1 = gen(now) , tmp2 = gen(now);
		while(tmp1 == tmp2) {tmp1 = gen(now);}
		cout << tmp1 << ' ' << tmp2 << endl;
	}

}

