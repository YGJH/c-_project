#include <bits/stdc++.h>
using namespace std;

int n , m;

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
int count = 0;
bool boad[100][100];
void solve(int x, int y) {
	if (x > m) {
		solve(0, y + 1);
		return;
	} else if (y >= n) {
		::count++;
		return;
	} else {
		if (boad[y][x] == 0) {
			boad[y][x] = 1;
			solve(y, x + 1);
			boad[y][x] = 0;
			if (boad[y][x + 1] == 0) {
				boad[y][x] = 1;
				boad[y][x + 1] = 1;
				solve(y, x + 1);
				boad[y][x] = 0;
				boad[y][x + 1] = 0;
			}
			if (boad[y + 1][x] == 0) {
				boad[y][x] = 1;
				boad[y + 1][x] = 1;
				solve(y, x + 1);
				boad[y][x] = 0;
				boad[y + 1][x] = 0;
			}
		} else {
			solve(y, x + 1);
		}
	}
    return;
}


int main() {
	re(n), re(m);
	memset(boad, 0, sizeof(boad));
	solve(0, 0);
    wr(::count);
}