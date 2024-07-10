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
// 競程者的吟唱
/* 12721, 13331, 14341, 75577, 123457, 222557, 556679
* 999983, 1097774749, 1076767633, 100102021, 999997771
* 1001010013, 1000512343, 987654361, 999991231
* 999888733, 98789101, 987777733, 999991921, 1010101333
* 1010102101, 1000000000039, 1000000000000037
* 2305843009213693951, 4611686018427387847
* 9223372036854775783, 18446744073709551557 */
#include <bits/stdc++.h>
#include <random>
#define mk make_pair
#define pb push_back
#define pll pair<long long ,long long>
#define pi acos(-1)
#define all(x) (x).begin(),(x).end()
#define ishowspeed ios_base::sync_with_stdio(0),cin.tie(nullptr) , cout.tie(0);
using ll = long long;
#define endl '\n'
#define lcm(a , b) ((a) * (b)) / __gcd(a ,b)
//ff#define int long long
#define ld long double
constexpr ld rad = 0.01745329252;
// #define int __int128
#define MOD 1000000009
#define cr(x) (x<<1)
#define cl(x) (x<<1)|1
#define mmax(a,b) (a > b)?a:b
#define mmin(a,b) (a<b)?a:b
using namespace std;
// ----------------------------------------------

// -----------------------------------------------
//template<typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
// ostream& operator<<(ostream& os , __int128 x) {
//   char st[128];
//   int now = 0;
//   if(x<0) x=-x,putchar('-');
//   while(x){
//     st[now++] = x % 10 + 48;
//     x/=10;
//   }
//   while(now){ putchar(st[--now]);}
//   return os;
// }
// istream& operator>>(istream& is , __int128 &x){
//   x=0;
//   char c = getchar();
//   bool w = 0;
//   while(c < 48 || c > 57) {w |= (c=='-'); c = getchar();}
//   while(c>47&&c<58) { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
//   if(w)x=-x;
//   return is;
// }

// template<typename T>
// ostream& operator<<(ostream& os, vector<T>& intermediate_array) { for (auto& a : intermediate_array) cout << a << ' '; return os; }
// template<typename T>
// istream& operator>>(istream& is, vector<T>& intermediate_array) { for (auto& a : intermediate_array) cin >> a; return is; }
// template<typename T>
// void print(T a) { cout << a << endl; }
// template<typename T, typename... Args>
// void print(T a, Args... b) { cout << a << " "; print(b...); } 
// template<typename T>
// void _debug(T a) {
//     if (typeid(a) == typeid(char)) cout << '\'';
//     if (typeid(a) == typeid(string)) cout << '\"';
//     cout << a;
//     if (typeid(a) == typeid(char)) cout << '\'';
//     if (typeid(a) == typeid(string)) cout << '\"';
//     cout << "]" << endl;
// }
// template<typename T, typename... Args>
// void _debug(T a, Args... b) {
//     if (typeid(a) == typeid(char)) cout << '\'';
//     if (typeid(a) == typeid(string)) cout << '\"';
//     cout << a;
//     if (typeid(a) == typeid(char)) cout << '\'';
//     if (typeid(a) == typeid(string)) cout << '\"';
//     cout << ",\t";
//     _debug(b...);
// }
// template<typename... Args>
// void debug(Args... b) { cout << '['; _debug(b...); }
 
// void swap(ll &x,ll &y){
//     ll temp = y;
//     y = x;
//     x = temp;
// }
// string dectobin(ll n)
// {
//     string s = bitset<64> (n).to_string();
//     const auto loc1 = s.find('1');
//     if(loc1 != string::npos)
//         return s.substr(loc1);
//     return "0";
// }

// void solve() {

// }

signed main() {
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    // mt19937 mt(hash<string>(":poop:"));
    uniform_int_distribution<> gen(1 , 10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ishowspeed
    
    cout << 34 << endl;

    return 0;
}