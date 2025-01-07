#pragma GC optimize(1)
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

struct op {
	int rs, cs, rt, ct;
};
struct mov {
	vector<pair<int, int>> node;
	char ch;
    int flo ;
    mov() {
        flo = 0;
    }
};
char bod[10][10];
vector<op> st;
vector<mov> rev;
int xx[] = {0, 1, -1};
int yy[] = {1, 0, 0};
int xxx[] = {0, 0, 1, 2, -1, -2};
int yyy[] = {1, 2, 0, 0, 0, 0};
bool fin = false;
bool w = false;
int n, m;
int kk;
int cou = 0;
int emli = 0;
bool cc(int y, int x) { return y < n && x < m; }
void check(int y, int x) {
	w = 0;
	char cur = bod[y][x];
	bool em = false;
    int fal=0;
	do {
		for (int i = 0; i < 3; i++) {
			em = false;
			for (int j = i * 2; j < i * 2 + 2; j++) {
				if (cc(yyy[j] + y, x + xxx[j])) {
					if (bod[y + yyy[j]][x + xxx[j]] == cur) {
						em = true;
					}
                    else {
                        em = false;
                        break;;
                    }
				} else {
                    em = false;
					break;
				}
			}
			if (em) {
				bod[y][x] = '*';
				mov tmp;
				emli++;
				tmp.node.push_back(make_pair(y, x));
				for (int j = i * 2; j < i * 2 + 2; j++) {
					bod[y + yyy[j]][x + xxx[j]] = '*';
					tmp.node.push_back(make_pair(y + yyy[j], x + xxx[j]));
					emli++;
				}
                tmp.flo = fal;
				tmp.ch = cur;
				rev.push_back(tmp);

				break;
			}
		}
		if (!em && y + 1 < n && bod[y + 1][x] == '*') {
			swap(bod[y][x], bod[y + 1][x]);
		}else{
            break;
        }
        fal++;
	} while (bod[y + 1][x] == '*' && !em);
}
void pull() {
	auto a = *prev(rev.end());
	for (auto tmp : a.node) {
		bod[tmp.first][tmp.second] = a.ch;
	}
    pair<int,int> tt = a.node[0];
    for(int i = 0 ; i < a.flo ; i++) {
        swap(bod[tt.first][tt.second] , bod[tt.first-1][tt.second-1]);
        tt.first -= 1;
    }
}
int mn = INT32_MAX;
vector<op> que;
void solve(int k, int x, int y) {
	if (fin || cou == emli) {
		if (mn > kk - k) {
			mn = kk - k;
			que.clear();
			for (auto &a : st) {
				que.push_back({a.rs, a.cs, a.rt, a.ct});
			}
		}
		return;
	}
	if (x > m && y < n) {
		solve(k, 0, y + 1);
	} else if (x > m || y >= n) {
		return;
	}
	if (bod[y][x] != '*') {
		for (int i = 0; i < 3; i++) {
            if(cc(y+yy[i] , x+xx[i])) {
                swap(bod[y + yy[i]][x + xx[i]], bod[y][x]);
                st.push_back({y, x, y + yy[i], x + xx[i]});
                check(y + yy[i], x + xx[i]);
                check(y, x);
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        cout << bod[i][j];
                    }
                    cerr << endl;
                }
                cerr << endl;
                solve(k - 1, y, x + 1);
                pull();
                st.pop_back();
                swap(bod[y + yy[i]][x + xx[i]], bod[y][x]);
            }
		}
	} else {
		solve(k, x + 1, y);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> kk;
	kk;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> bod[i][j];
			if (bod[i][j] != '*')
				cou++;
		}
	}
	solve(kk, 0, 0);
    if(mn == INT32_MAX) {
        cout << -1 << endl;
    }else {
        cout << mn << endl;
        reverse(que.begin(), que.end());
        for (int i = 0; i < mn; i++) {
            auto as = *prev(que.end());
            cout << as.rs + 1 << ' ' << as.cs + 1 << ' ' << as.rt + 1 << ' '
                << as.ct + 1 << endl;
            que.pop_back();
        }
    }

	return 0;
}
