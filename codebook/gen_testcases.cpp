#include<bits/stdc++.h>
#include<random>
#define pii pair<int,int>
#define pb push_back
using namespace std;
signed main() {
	const int N = 6;
	mt19937 now(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<> gen(1 , 20);
	cout << N << endl;
	for(int i = 0 ; i < N ; i++) 
		cout << gen(now) << endl;
	return 0;


}

