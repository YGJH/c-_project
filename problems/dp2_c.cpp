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
#define mk make_pair
#define pb push_back
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define ishowspeed ios_base::sync_with_stdio(0),cin.tie(nullptr);
#define endl '\n'
#define lcm(a , b) (a * b) / __gcd(a ,b)
using ll = long long;
#define pause printf("Press any key to continue...\n") , fgetc(stdin);
#define int long long
// #define int __int128
#define lowbit(x) (x&-x)
#define MOD 1000000007
#define MXN 400'500
#define cr(x) (x<<1)
#define cl(x) (x<<1)+1
#define mmax(a,b) (a > b)?a:b
#define mmin(a,b) (a<b)?a:b
using namespace std;
const int N=1e5+5;

inline int poww(int a , int b) {
	int ret = 1;
	for( ; b ; b >>= 1 , a = (a % MOD) * (a % MOD) % MOD) {
		if(b &  1) {
			ret *= a ;
			ret %= MOD;
		}
	}
	return ret % MOD;
}


// namespace int128IO {
// 	istream& operator>>(istream& is, __int128& i) {
// 		string s; is>>s; i = 0;
// 		auto c=s.begin(); c+=(s[0]=='-');
// 		for(; c!=s.end(); ++c) i=i*10+(*c-'0');
// 		if(s[0]=='-') i=-i;
// 		return is;
// 	}
// 	ostream& operator<<(ostream& os, __int128 i) {
// 		string s; bool neg=false; if(i<0) neg=true, i=-i;
// 		while(i) s+=('0'+i%10), i/=10;
// 		if(neg) os<<'-';
// 		for(auto c=s.rbegin();c!=s.rend();++c) os<<*c;
// 		return os;
// 	}
// }

template<class io>
inline void re(io &x) {
	io c = getchar();int w = 0 ; x = 0;
	while(c < 48 || c > 57) w|=c==45,c=getchar();
	while(c > 47 && c < 58)x=(x<<3)+(x<<1)+(c&15),c=getchar();
	x=w?-x:x;return;
}
template <class io>
inline void wr(io x) {
	if(x < 0) 
		putchar('-'), x=~x,x++;
  static int sta[300];
  int top = 0;
  do {
	sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}

ll inv(ll x){
	return poww(x, MOD-2);
}


template<class T, T M> class modular {
	T value;
	public:
	modular(T val=T()) {
		value = val;
		value %= M; while(value<0)value+=M; if(value>=M)value%=M;
	}
	template<class P> modular(P val) {
		value = val;
		value %= M; while(value<0)value+=M; if(value>=M)value%=M;
	}
	
	T pow(T a, T b) {
		T ret=1;
		for(a%=M; b; b>>=1, a=a*a%M) if(b&1) ret=ret*a%M;
		return ret;
	}
  	modular pow(T p) {return pow(value, p);}
	modular operator+(modular m) {return modular(value+m.value);}
	modular operator-(modular m) {return modular(value-m.value);}
	modular operator*(modular m) {return modular(value*m.value);}
	modular operator/(modular m) {return modular(value*pow(m.value, M-2));} // works if M is prime
	modular operator+=(modular m) {*this=operator+(m); return *this;}
	modular operator-=(modular m) {*this=operator-(m); return *this;}
	modular operator*=(modular m) {*this=operator*(m); return *this;}
	modular operator/=(modular m) {*this=operator/(m); return *this;}
	modular operator++() {*this=operator+(1); return *this;}
	modular operator++(int) {modular r=*this; operator++(); return r;}
	modular operator--() {*this=operator-(1); return *this;}
	modular operator--(int) {modular r=*this; operator--(); return r;}
	template<class P> friend modular operator-(P v, modular m) {return modular(v-m.value);}
	template<class P> friend modular operator/(P v, modular m) {return modular(v)/m;}
	T get() {return value;}
	//operator T() {return value;}

	bool operator==(modular m) {return value==m.value;}
	bool operator!=(modular m) {return value!=m.value;}
	bool operator<(modular m) {return value<m.value;}
	bool operator>(modular m) {return value>m.value;}
	bool operator<=(modular m) {return value<=m.value;}
	bool operator>=(modular m) {return value>=m.value;}

	friend istream& operator>>(istream& is, modular& m) {is>>m.value; return is;}
	friend ostream& operator<<(ostream& os, modular m) {os<<m.value; return os;}
};

using Mod = modular<ll, (ll)1e9+7>;
int factor[(ll)(2e6+3)];
int n , m;
vector<int> dp(2003 , 0);
pair<int,int> trap[2003];
inline void fac() {
	factor[0] = 1;
	for(int i = 1 ; i < (ll)2e6 + 1 ; i++) {
		factor[i] = (factor[i-1]%MOD) * (i%MOD) % MOD;
	}
}
bool cmp(pair<int,int> a , pair<int,int> b) {
	return a.first + a.second < b.first + b.second;
}
int C_cal(int n , int m) {
	if(n <= 0 || m <= 0) {
		return 0 ;
	}
	int tmp = factor[n + m] ;
	m = factor[m];
	n = factor[n];
	return ( ( ((tmp%MOD) * (inv(m)%MOD)) % MOD ) * (inv(n) % MOD) ) % MOD;
}
void print_dp(int m ) {
	for(int i = 0 ; i <=  m ; i ++) {
		cerr << dp[i] << ' ' ;
	}
	cerr << endl;
}

void solve() {
	re(n);
	re(m);
	for(int i = 0 ; i < m ; i++) {
		re(trap[i].first) ,  re(trap[i].second);
		if(trap[i].first == n && trap[i].second == n ) {
			wr(0);
			return;
		}
		trap[i].first -= 1;
		trap[i].second -= 1;
	}
	int x = n - 1, y = n - 1 ;
	// m++;
	// trap[m-1] = {n - 1, n - 1};
	sort(trap , trap + m , cmp);
	int now = 0;
	int px , py;
	int tmp;
	int tmp2 = 0;
	for(int i = 0 ; i < m ; i++) {
		dp[i] = C_cal(trap[i].first , trap[i].second) % MOD;
		tmp2 = C_cal(x - trap[i].first, y - trap[i].second);
		if(tmp2 <= 0) {
			tmp2 = 1;
		}
		dp[i] = (dp[i] % MOD) * (tmp2 % MOD);
		dp[i] %= MOD;
		for(int j = 0 ; j < i ; j++) {
			tmp = C_cal(trap[j].first , trap[j].second) % MOD;
			tmp2 = C_cal(trap[i].first - trap[j].first , trap[i].second - trap[j].second)%MOD;
			if(tmp <= 0){
				tmp = 1;
			}
			if(tmp2 <= 0) {
				tmp2 = 1;
			}
			tmp = (tmp * tmp2) %MOD;
			int tmp3 = C_cal(x - trap[i].first , y - trap[i].second)%MOD;
			if(tmp3 <= 0) {
				tmp3 = 1;
			}
			tmp = (tmp * tmp3)%MOD;
			if(dp[j] - tmp < 0) {
				dp[j] = 0;
			}
			dp[j] -= tmp;
		}
		print_dp(i);
	}
	int ans = C_cal(x ,y);
	int sum = 0;
	for(auto I : dp) {
		sum += I;
	}
	// cerr << "ans = " << ans << endl;
	wr(ans - sum );
	return;
}

signed main() {

	// ishowspeed
	fac();
	solve();
	return 0;
}