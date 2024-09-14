#include <bits/stdc++.h>
using namespace std;
char st[40];
int now = 0;
inline void wr(int a) {
	now = 0;
    if(a==0) {
        putchar('0');
        return ;
    }
	if (a < 0)
		putchar('-'), a = -a;
	while (a) {
		st[now++] = a % 10 + '0';
		a /= 10;
	}
	while (now) {
		putchar(st[--now]);
	}
	return;
}
int32_t main() {
    for(int i = -19 ; i < 100 ; i++) {
        wr(i);
        putchar('\n');
    }
}