#pragma G++ optimize(3)
#pragma G++ optimize("-Ofast")
#pragma G++ optimize("inline")
#include <bits/stdc++.h>
#define endl '\n'
const int MOD = 1e9 + 7;
#define int long long
using namespace std;
int mat[2][2] = {{0, 1}, {1, 1}};
// template<size_t N , size_t M>
inline void multiplex_matrix()
{
    int a = mat[0][0] % MOD, b = mat[0][1] % MOD, c = mat[1][0] % MOD,
        d = mat[1][1] % MOD;
    mat[0][0] %= MOD;
    mat[0][1] %= MOD;
    mat[1][0] %= MOD;
    mat[1][1] %= MOD;
    mat[0][0] = (((a * a) % MOD) + ((b * c) % MOD)) % MOD;
    mat[0][1] = (((a * b) % MOD) + ((b * d) % MOD)) % MOD;
    mat[1][0] = (((c * a) % MOD) + ((c * d) % MOD)) % MOD;
    mat[1][1] = (((c * b) % MOD) + ((d * d) % MOD)) % MOD;
    return;
}
template <size_t S> inline void matrix_t(int (&init)[S])
{
    int a = init[0] % MOD, b = init[1] % MOD;
    init[0] %= MOD;
    init[1] %= MOD;
    init[0] = (((mat[0][0] * a) % MOD) + ((mat[0][1] * b) % MOD)) % MOD;
    init[1] = (((mat[1][0] * a) % MOD) + ((mat[1][1] * b) % MOD)) % MOD;
    return;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int init[] = {0, 1};
    for (; n; n >>= 1, multiplex_matrix())
    {
        if (n & 1)
        {
            matrix_t(init);
        }
    }
    // matrix();
    // for(int i = 0 ; i < 2 ; i++) {
    //     for(int j = 0 ; j < 2 ; j++) {
    //         cout << mat[i][j] << " \n"[j==1];
    //     }
    // }
    cout << init[0] << endl;
    return 0;
}