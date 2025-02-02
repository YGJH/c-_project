#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma G++ optimize(1)
#pragma G++ optimize(2)
#pragma G++ optimize(3)
#pragma G++ optimize("Ofast")
#pragma G++ optimize("inline")
#pragma G++ optimize("-fgcse")
#pragma G++ optimize("-fgcse-lm")
#pragma G++ optimize("-fipa-sra")
#pragma G++ optimize("-ftree-pre")
#pragma G++ optimize("-ftree-vrp")
#pragma G++ optimize("-fpeephole2")
#pragma G++ optimize("-ffast-math")
#pragma G++ optimize("-fsched-spec")
#pragma G++ optimize("unroll-loops")
#pragma G++ optimize("-falign-jumps")
#pragma G++ optimize("-falign-loops")
#pragma G++ optimize("-falign-labels")
#pragma G++ optimize("-fdevirtualize")
#pragma G++ optimize("-fcaller-saves")
#pragma G++ optimize("-fcrossjumping")
#pragma G++ optimize("-fthread-jumps")
#pragma G++ optimize("-funroll-loops")
#pragma G++ optimize("-fwhole-program")
#pragma G++ optimize("-freorder-blocks")
#pragma G++ optimize("-fschedule-insns")
#pragma G++ optimize("inline-functions")
#pragma G++ optimize("-ftree-tail-merge")
#pragma G++ optimize("-fschedule-insns2")
#pragma G++ optimize("-fstrict-aliasing")
#pragma G++ optimize("-fstrict-overflow")
#pragma G++ optimize("-falign-functions")
#pragma G++ optimize("-fcse-skip-blocks")
#pragma G++ optimize("-fcse-follow-jumps")
#pragma G++ optimize("-fsched-interblock")
#pragma G++ optimize("-fpartial-inlining")
#pragma G++ optimize("no-stack-protector")
#pragma G++ optimize("-freorder-functions")
#pragma G++ optimize("-findirect-inlining")
#pragma G++ optimize("-frerun-cse-after-loop")
#pragma G++ optimize("inline-small-functions")
#pragma G++ optimize("-finline-small-functions")
#pragma G++ optimize("-ftree-switch-conversion")
#pragma G++ optimize("-foptimize-sibling-calls")
#pragma G++ optimize("-fexpensive-optimizations")
#pragma G++ optimize("-funsafe-loop-optimizations")
#pragma G++ optimize("inline-functions-called-once")
#pragma G++ optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
#define mxn 50005
#define int uint64_t

const uint32_t cost[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int dp[20005][11];
int vis[20005];

bool w = 0;
char c;
template <typename T> inline void re(T &a) {
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
char st[300];
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
bool digi;
int n, m, i, j, sumi, sumj, k, p;
vector<uint32_t> v(15);
signed main() {
	auto cmp = [](int i, int j) {
		sumi = 0, sumj = 0;
		digi = false;
		for (int k = 9; k >= 1; --k) {
			if (dp[i][k] != dp[j][k]) {
				digi = dp[i][k] > dp[j][k];
			}
		}
		for (int k = 9; k >= 1; --k) {
			sumi += dp[i][k];
			sumj += dp[j][k];
		}
		if (sumi == sumj)return digi;
		return (sumi > sumj);
	};

    re(n);
    re(m);
	vis[0] = 1;
	for (i = 0; i < m; i++) {
        re(v[i]);
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j <= n ; j++) {
			if (j - cost[v[i]] >= 0 && vis[j - cost[v[i]]] ) {
				++dp[j-cost[v[i]]][v[i]];
                if (  cmp(j - cost[v[i]], j)  ) {
					for (p = 1; p < 10; p++)
						dp[j][p] = dp[j - cost[v[i]]][p];
				}
				--dp[j-cost[v[i]]][v[i]];
				vis[j] = 1;
        	}
		}
	}
	for (i = 9; i >= 1; --i) {
		for (j = 0; j < dp[n][i]; ++j) {
			wr(i);
		}
	}

	return 0;
}