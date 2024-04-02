#include <bits/stdc++.h>
#include <bits/extc++.h>

#define int long long
#define pii pair<int,int>
#define ishowspeed ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define cl(x) (x<<1)
#define cr(x) (x<<1|1)
using namespace std;
using namespace __gnu_pbds;
typedef struct{
    int a , b , c , d;
}Node;

const int N = 1e5 + 3;
struct Arearection{ 
    int n , id , sid;
    pii tree[N<<3];
    vector<int> ind;
    Node scan[N << 1];
    void init(int _n) {
        n = _n;
        id = sid = 0;
        ind.clear();
        ind.resize(n<<1);
        for(int i = 0 ; i < n + 2 ; i++ ) {
            tree[i].first = 0 ; tree[i].second = 0;
        }
    }
    void puint(int i , int l , int r) {
        if(tree[i].first) 
            tree[i].second = ind[r + 1] - ind[l];
        else if ( l != r ) {
            int mid = (l + r) >> 1;
            tree[i].second = tree[cl(i)].second + tree[cr(i)].second;
        }
        else 
            tree[i].second = 0;
    }
    void addRectangle(int lx , int ly , int rx , int ry ) {
        ind[id++] = lx;
        ind[id++] = rx;
        scan[sid++] = {ly , 1 , lx  , rx};
        scan[sid++] = {ry , -1 , lx , rx};
    }
    void upd(int i , int l , int r , int ql , int qr , int v) {
        if(ql <= l && r <= qr) {
            tree[i].first += v ;
            puint(i , l , r);
            return;
        }
        int mid = (l + r) >> 1;
        if (ql <= mid) 
            upd(cl(i) ,  l , mid , ql , qr , v);
        if (qr < mid) 
            upd(cr(i) , mid + 1 , r , ql , qr , v);
        puint(i , l , r); 
    }
    int solve() {
        sort(all(ind));
        ind.resize(unique(all(ind)) - ind.begin()); // 離散化
        sort(scan , scan + sid);
        int area = 0 , pre = scan[0].a;
        for(int i  =0  ; i < sid ; i++ ) {
            auto [x, v , l , r] = scan[i];
            area += tree[1].second * (x - pre);
            upd(1 , 0 , ind.size() - 1 , 
            lower_bound(ind.begin() , ind.end() , l) - ind.begin() ,
            lower_bound(ind.begin() , ind.end() , r) - ind.begin() - 1 , v);
            pre = x;
        }
        return area;
    }

};


signed main() {

    ishowspeed

    return 0;
}
