#include <iostream>
using namespace std;
int josephus(int n, int m){	//n人每m次
    int ans = 0;
    for (int i=1; i<=n; ++i)
        ans = (ans + m) % i;
    return ans;
}
int josephus(int n, int k) {
  if (n == 1) return 0;
  if (k == 1) return n - 1;
  if (k > n) return (josephus(n - 1, k) + k) % n;
  int res = josephus(n - n / k, k);
  res -= n % k;
  if (res < 0) res += n;
  else res += res / (k - 1);
  return res;
}
int32_t main() {
    return 0;
}