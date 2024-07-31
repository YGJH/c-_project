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
#define mk make_pair
#define pb push_back
#define ishowspeed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
using ll=long long;
// #define int long long
struct Node {
    int st , des; 
    ll id;
    ll dis;
    Node(int st_ ,int des_ , int dis_ , int id_) :st(st_), des(des_) , dis(dis_) , id(id_) {};
    Node() : st(0) , des(0),dis(0) , id(0){};
    friend bool operator<(const Node &a , const Node &b) {
        return a.dis > b.dis;
    }
};
const int MXN = 3e6;
const int INF = 1e18;
vector<ll> dis(MXN , INF);
vector<vector<Node>> edge(MXN);
int n , m;
vector<int> ans;
vector<bool> vis(MXN , false);
void solve() {
    priority_queue<Node> que;
    que.push({1 , 0  , 0 , 0});
    dis[1] = 0;
    while(!que.empty()) {
        auto nb = que.top(); que.pop();
        if(vis[nb.st]) continue;
        vis[nb.st] = 1;
        // cerr << nb.st << ' ' << nb.id << endl;
        ans.emplace_back(nb.id);
        for(auto &nxt : edge[nb.st]) {
            // cerr << dis[nxt.des] << ' ' << dis[nxt.st] << ' ' << nxt.dis << endl;
            if(dis[nxt.des] > dis[nxt.st] + nxt.dis) {
                dis[nxt.des] = dis[nxt.st] + nxt.dis;
                que.push({nxt.des , 0 , dis[nxt.des] , nxt.id});
            }
        }
    }
}
signed main() {
    // mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    // mt19937 mt(hash<string>(":poop:"));
    // uniform_int_distribution<> gen(1 , 10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ishowspeed
    cin >> n >> m ;
    int tmp1 , tmp2 , tmp3;
    for(int i = 1 ; i <= m ; i++) {
        cin >> tmp1 >> tmp2 >> tmp3;
        edge[tmp1].pb({tmp1 , tmp2 , tmp3 , i});
        edge[tmp2].pb({tmp2 , tmp1 , tmp3 , i});
    }
    solve();
    for(auto &i : ans) {
        if( i!=0 ) {
            cout << i << ' ';
        }
    }
    return 0;
}