#include <bits/stdc++.h>
using namespace std;
#define int long long
bool w = 0; char c;
template<typename T>
inline void re(T& a) {
	w = 0;c = getchar();	a = 0; while (c < '0' || c > '9') w |= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9') a = (a << 1) + (a << 3) + (c & 15), c = getchar();
	if (w) a = -a;
	return;
}
char st[300]; int kkkk = 0;
template<typename T>
inline void wr(T a) {
	kkkk = 0;
	if (a == 0) { putchar('0'); return; }
	if (a < 0)putchar('-'), a = -a;
	while (a) { st[kkkk++] = a % 10 + '0', a /= 10; }
	while (kkkk) { putchar(st[--kkkk]); }
	return;
}
namespace my
{
	int pow(int a, int b) {
		wr(a);
		putchar('\n');
		int ret = 1;
		for (; b ; b >>= 1, a = a * a) {
			if(b&1) {
				wr(a);
				putchar('\n');
				ret *= a;
				wr(ret);
				putchar('\n');
			}
		}
		return ret;
		
	} // namespace my

}

signed main() {
	// cout << (1 << 30) << endl;
	int a = 123;
	stringstream ss;
	ss << a;
	string b;
	ss >> b;
	cout << b << endl;
	cout << b.length() << endl;
	// for(auto i : iota_view{1 , 30}) {
	// 	cout << i << ' ';
	// }
	vector<int> f(100);
	iota(f.begin() , f.end() , 1);
for (int i : f) // iterate over a view of the integers 1 through 9
{
    std::cout << i << ' '; // 1 2 3 4 5 6 7 8 9
}

	return 0;
}