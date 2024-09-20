#include <bits/stdc++.h>
using namespace std;
bool w = 0;
char c;
inline void re(int &a) {
	c = getchar();
	a = 0;
	while (c < '0' || c > '9')
		w |= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9')
		a = (a << 1) + (a << 3) + (c & 15), c = getchar();
	if (w)
		a = -a;
	return;
}
char st[30];
int kkkk = 0;
inline void wr(int a) {
	if (a == 0) {
		putchar('0');
		return;
	}
	if (a < 0)
		putchar('-'), a = -a;
	while (a) {
		st[kkkk++] = a % 10 + '0', a /= 10;
	}
	while (kkkk) {
		putchar(st[--kkkk]);
	}
	return;
}
void solve() {
    int n , k ; re(n) , re(k);
    
}
int32_t main() {
    int T;
    re(T);
    while(T--) {
        solve();
    }

	return 0;
}