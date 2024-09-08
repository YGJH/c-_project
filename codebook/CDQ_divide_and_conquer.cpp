#include <iostream>
using namespace std;

void cdq(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    cdq(l, mid);
    cdq(mid + 1, r);
    merge(l, r);
}
int32_t main() {
    return 0;
}