#include <iostream>
using namespace std;
// does not work when n is prime  O(n^(1/4))

int mul(int x,  int y , int p) {
    return (x * y) % p;
}
int add(int a , int b , int c) {
    return (a + b) % c;
}
LL f(LL x, LL c, LL mod) { return add(mul(x, x, mod), c, mod); }
LL pollard_rho(LL n)
{
    LL c = 1, x = 0, y = 0, p = 2, q, t = 0;
    while (t++ % 128 or gcd(p, n) == 1)
    {
        if (x == y)
            c++, y = f(x = 2, c, n);
        if (q = mul(p, abs(x - y), n))
            p = q;
        x = f(x, c, n);
        y = f(f(y, c, n), c, n);
    }
    return gcd(p, n);
}

#define i64 __int64

vector<i64> ret;
// 利用 pollard_rho 找到所有質因數
void fact(i64 x) {
      if (miller_rabin(x)) {
          ret.push_back(x);
          return;
      }
      i64 f = pollard_rho(x);
      fact(f); fact(x/f);
}

int32_t main()
{
    int c;
    cin >> c;
    cout << pollard_rho(c);
    return 0;
}