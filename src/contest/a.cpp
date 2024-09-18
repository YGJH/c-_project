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
#define int long long
int n , m;
bool w;
char c;
inline void re(int &a) {
	a=0;
	c=getchar();
	w=0;
	while(c<'0'||c>'9') w|=(c=='-'), c=getchar();
	while(c>='0' && c<='9')a=(a<<1)+(a<<3)+(c&15) , c=getchar();
	if(w) a=-a;
	return ;
}
int nn;
char st[40];
inline void wr(int a) {
	if(a==0){
		putchar('0');
		return ;
	}
	if(a<0) {
		putchar('-') , a=-a;
	}
	while(a) {
		st[nn++] = a%10 +'0';
		a/=10;
	}
	while(nn) {
		putchar(st[--nn]);
	}
	return ;
}
// unordered_map<int , int> mp;
vector<int> mp;
// vector<int> mp(1e9)
int arr[2001];
int out[2001];
int32_t main() {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cin >> n >> m;
	re(n) , re(m);
	for(int i = 0 ; i < n ; i++) {
		re(arr[i]);
		// cin >> arr[i];
	}
	for(int j = 0 ; j < m ; j++) {
		re(out[j]);
		// cin >> out[j];
	}
	int mx = 0;
	int ans = 1e9;
	int j=0, i=0;
	// int cou = min(m , n);
	bool kk = 0;
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < m ; j++) {
			if(out[j] - arr[i] < 0) continue;
			mp.push_back(out[j] - arr[i]);
			// cerr << out[j]-arr[i] << endl;
			// mp[out[j] - arr[i]]+=1;
			kk=1;
		}
	}
	if(!kk) {
		putchar('0');
		return 0;
	}
	sort(mp.begin() , mp.end());
	int now = mp[0] , count = 0;
	for(auto &a : mp) {
		if(now==a) {
			count++;
		}
		else {
			if(mx < count) {
				mx = count;
				ans = now;
			}
			count=1;
		}
		now = a;
	}
	if(count > mx){
		ans = *prev(mp.end());
	}
	wr(ans);
 
	return 0;	
}