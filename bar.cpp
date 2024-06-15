#include <iostream>
#define ishowspeed ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define pb push_back
signed main() {
//	ishowspeed	
	int i;
	double j;
	const long long N = 10000000;
	double per = 0;
	for(i = 0  ; i < N ; i++) {
//		tmp.pb('■');
		//cout << '\r' << "| " << tmp << " |" ;
		printf("\r| ");
		double time = (double)i / N * 40;
		for(j = 0 ; (time - j) > (double)1e-9 ; j++) 
			putchar('B');
		for(; 40- j > (double)1e-9 ; j++) {
			putchar('D');
		}
		per = (double)i / N * 100;
		cout << " | " << per << " %";
		cout << "            "; 
	}
	return 0;
}
