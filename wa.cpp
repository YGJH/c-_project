#pragma G++ optimize(3)
#pragma G++ optimize("Ofast")
#pragma G++ optimize("inline")
#pragma G++ optimize("-bmi -bmi2 -popcnt -abm -lzcnt -tbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm")
#include <bits/stdc++.h>
using namespace std;
int T, n, k, a[200005], flag;
bool w = 0;
char c;
template <typename T> inline void re(T &&a) {
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
template <typename T> inline void wr(T a) {
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
 inline void solve() {
	re(n);
	re(k);
	flag = 1;
    auto p = n;
    auto tmp = a + 1;
    while(p--) 
        re((*tmp++));
	if (n == k) {
		for (int i = 2; i <= n; i += 2) {
			if (a[i] != (i>>1)) {
                wr((i>>1));
                putchar('\n');  
                return;
             }
        }
        wr((n>>1)+1);
        putchar('\n');
        return;
	} else {
		for (int i = 2; i <= n - k + 2 && flag ; i++)
			flag &= (a[i] == 1);
		wr(1 + flag);
		putchar('\n');
        return;
	}
}
int main() {
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// cin >> T;
	re(T);
	while (T--)
		solve();
	return 0;
}
