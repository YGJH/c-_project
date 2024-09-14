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
#define int long long
// mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
struct treap {
	treap *l, *r;
	int sz, pri, key;
	int tag;
	treap(int key_) : tag(0), key(key_), pri(rand()), sz(1) { l = r = nullptr; }
};
// constexpr int MXN = 1000050;
// int arr[MXN];
vector<int> arr;
treap *root = nullptr;
int n, q;
int q1, q2;
int Size(treap *a) { return a ? a->sz : 0; }
void pull(treap *a) { a->sz = Size(a->l) + Size(a->r) + 1; }

// void push(auto x) {
//     if(x->tag) {
//         x->key += x->sz * x->tag;
//         if(x->l) x->l->tag += x->tag;
//         if(x->r) x->r->tag += x->tag;
//         x->tag = 0;
//     }
// }
treap *merge(treap *a, treap *b) {
	if (!a || !b)
		return a ? a : b;
	if (a->pri > b->pri) {
		a->r = merge(a->r, b);
		pull(a);
		return a;
	} else {
		b->l = merge(a, b->l);
		pull(b);
		return b;
	}
}

void split_by_size(treap *x, int k, treap *&a, treap *&b) {
	if (!x) {
		a = b = nullptr;
		return;
	}
	// push(x);
	if (Size(x->l) + 1 <= k) {
		a = x;
		split_by_size(x->r, k - Size(x->l) - 1, a->r, b);
		pull(a);
	} else {
		b = x;
		split_by_size(x->l, k, a, b->l);
		pull(b);
	}
}
void split_by_key(treap *x, int k, treap *&a, treap *&b) {
	if (!x) {
		a = b = nullptr;
		return;
	}
	if (x->key <= k) {
		a = x;
		split_by_key(x->r, k, a->r, b);
		pull(a);
	} else {
		b = x;
		split_by_key(x->l, k, a, b->l);
		pull(b);
	}
}
void insert(int x) {
	treap *a, *b;
	split_by_key(root, x, a, b);
	root = merge(a, merge(new treap(x), b));
}
// void erase(int x) {
//     treap *a , *b , *mid;
//     split_by_key(root , x , a ,b);
//     split_by_key(a , x-1 , a , mid);
//     merge(merge(a, merge(mid->l , mid->r)) , b);
// }
// void add_range(int val ,int L , int R) {
//     treap *l , *r , *m;
//     split_by_key(root , R , l , r);
//     split_by_key(l , L-1 , l , m);
//     m->tag += val;
//     merge(l , merge(m , r));
// }
inline void re(int &a) {
	a = 0;
	bool w = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		w = (c == '-'), c = getchar();
	}
	while (c >= '0' && c <= '9') {
		a = (a << 3) + (a << 1) + (c & 15);
		c = getchar();
	}
	if (w)
		a = -a;
	return;
}
// inline void wr(int a) {
// 	char t[30];
// 	int now = 0;
// 	// if (a < 0)
// 	// 	putchar('-'), a = -a;
// 	while (a) {
// 		t[now++] = a % 10 + '0';
// 		a /= 10;
// 	}
// 	while (now) {
// 		putchar(t[--now]);
// 	}
// 	return;
// }
char st[40];
int now;
inline void wr(int s) {
	now=0;
	if(s==0) {
		putchar('0');
		return ;
	}
	while(s) {
		st[now++] = s%10+48;
		s/=10;
	}
	while(now) {
		putchar(st[--now]);
	}
	return ;
}

int size_of(int x, treap *now) {
	if (!now) {
		return 0;
	}
	if (now->key <= x) {
		return 1 + Size(now->l) + size_of(x, now->r);
	} else {
		return size_of(x, now->l);
	}
}
#define endl '\n'
int32_t main() {
	srand(time(nullptr));

	re(n), re(q);
	// cin >> n >> q;
	arr.resize(n);
	for (auto &v : arr) {
		re(v);
		// cin >> v;
	}
	int tmp;
	sort(arr.begin(), arr.end());
	for (auto &a : arr) {
		root = merge(root, new treap(a));
	}
	int count = 0;
			treap *l, *m, *r;
	while (q--) {
		// cin >> q1 >> q2;
		re(q1), re(q2);
		if (q1 == 1) {
			count = size_of(q2, root);
			insert(count + q2);
		} else if (q1 == 2) {
			tmp = size_of(q2, root);
			wr(tmp);
			// cout << tmp;
			putchar('\n');
		} else {
			if (q2 > Size(root)) {
				putchar('i');
				putchar('n');
				putchar('v');
				putchar('a');
				putchar('l');
				putchar('i');
				putchar('d');
				putchar('\n');
				// cout << "invalid" << endl;
				continue;
			}
			split_by_size(root, q2, l, r);
			split_by_size(l, q2 - 1, l, m);
			root = merge(l, merge(m, r));
			wr(m->key);
			// cout << m->key;
			putchar('\n');
		}
	}
	return 0;
}