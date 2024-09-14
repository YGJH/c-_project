/*
I am the bone of my sword.
Steel is my body, and fire is my blood.
I have created over a thousand blades.
Unknown to Death.
Nor known to Life.
Have withstood pain to create many weapons.
Yet, those hands will never hold anything.
So as I pray, "Unlimited Blade Works".
*/
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
int n, q;
string arr;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
struct Treap {
	int sz, pri;
	char key;
	bool rev;
	Treap *l, *r;
	// Treap(){};
	Treap(char key_) {
		rev = 0;
		l = r = nullptr;
		// pri = gen();
		pri = gen();
		sz = 1;
		key = key_;
	}
};
Treap *root = nullptr;
int Size(Treap *&m) { return m ? m->sz : 0; }
void pull(Treap *&m) { m->sz = Size(m->l) + Size(m->r) + 1; }
void push(Treap *&x) {
	if (x != nullptr && x->rev) {
		swap(x->l, x->r);
		if (x->l) {
			x->l->rev ^= true;
		}
		if (x->r) {
			x->r->rev ^= true;
		}
		x->rev = false;
	}
}
Treap *merge(Treap *a, Treap *b) {
	if (!a || !b)
		return (a) ? a : b;
	if (a->pri > b->pri) {
	push(a);
		a->r = merge(a->r, b);
		pull(a);
		return a;
	} else {
	push(b);
		b->l = merge(a, b->l);
		pull(b);
		return b;
	}
}

void split_by_size(Treap *x, int ss, Treap *&a, Treap *&b) {
	if (!x) {
		a = nullptr;
		b = nullptr;
		return;
	} else {
		push(x);
		if (Size(x->l) + 1 <= ss) {
			a = x;
			split_by_size(x->r, ss - Size(x->l) - 1, a->r, b);
			pull(a);
		} else {
			b = x;
			split_by_size(x->l, ss, a, b->l);
			pull(b);
		}
	}
	return;
}

string ans = "";
void dfs(Treap* ro) {
	if (!ro)
		return;
	push(ro);
	dfs(ro->l);
	ans += ro->key;
	dfs(ro->r);
	return;
}

#define endl '\n'
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int l, r;
	cin >> n >> q;
	cin >> arr;
	for (int i = 0; i < n; i++) {
		root = merge(root, new Treap(arr[i]));
	}
	while (q--) {
		cin >> l >> r;
		Treap *left, *rig, *m;
		split_by_size(root, r, left, rig);
		split_by_size(left, l - 1, left, m);
		m->rev ^= true;
		root = merge(left, merge(m, rig));
	}
	dfs(root);
	int now = 0;
	while (n > now) {
		putchar(ans[now++]);
	}
}