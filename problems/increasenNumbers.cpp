#include <bits/stdc++.h>
#define mk make_pair
#define pb push_back
#define ishowspeed ios_base::sync_with_stdio(0),cin.tie(nullptr);
#define ll long long
#define endl '\n'
#define lcm(a , b) (a * b) / __gcd(a ,b)
#define pause printf("Press any key to continue...\n") , fgetc(stdin);
#define int long long
using namespace std;

inline int poww(int a , int b) {
    int ret = 1;
    for( ; b ; b >>= 1 , a *= a) {
        if(b &  1) {
            ret *= a;
        }
    }
    return ret;
}

template<class io>
inline void re(io &x) {
    io c = getchar();int w = 0 ; x = 0;
    while(c < 48 || c > 57) w|=c==45,c=getchar();
    while(c > 47 && c < 58)x=(x<<3)+(x<<1)+(c&15),c=getchar();
    x=w?-x:x;return;
}
inline void wr(int x) {
    if(x < 0) 
        putchar('-'), x=~x,x++;
  static int sta[300];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}

inline int mmax(int x ,int y){
    return x > y ? x : y ;
}
inline int mmin(int x ,int y){
    return x < y?x:y;
}

bool const operator == (pair<int,int> &a , pair<int,int> &b){
    if(a.first==b.first && a.second == b.second) return true;
    else return false;
}

vector<vector<int>> ve;//數字的位置
static vector<int> kk;
void solve() {
    int a;
    re(a);
    int num[a], length[a] , now[a];
    vector<vector<int>> backtracking;//紀錄下一個數字的位置
    multiset<int> se;
    for(int i = 0 ; i < a; i ++)  backtracking[i].pb(-1) , length[i] = 1 ,now[i]=0, re(num[i]);
    int len;
    re(len);
    for(int i = 0 ; i < a; i++) {
        if(se.empty()) {
            se.insert(num[i]);
            now[i]=num[i];
        }
        else {
            auto it = upper_bound(se.begin(),se.end() ,num[i] );
            if(it == se.begin()) { //代表這個比所有的數字小
                se.insert(num[i]);
            }
            else {
                for(auto j = se.begin() ; j != se.end() ; j++ ) {
                    if(*j >= num[i]) {
                        break;
                    }
                    else {
                        auto now2 = ve[*j];
                        for(auto k = now2.begin() ; k != now2.end() ; k++ ) {
                            if(now[*k] > num[i] ) {
                                now[*k]=num[i];//代表潜力比它大
                                backtracking[*k].pb(i);
                            }
                        }
                    }
                }
            }
        }
        ve[num[i]].pb(i);

    }
    for(int i = 0 ; i < a ; i++) {
        vector<int> now3 = backtracking[i];
        if(now3.size() != 1) {
            auto k = 
            while(auto k = now3.begin() ; k != now3.end()  ) {
                
            }
        }
    }
    ve.claer();
}



signed main() {
    // mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    // uniform_int_distribution<> gen(1 , 10);
    int a;
    re(a);
    while(a--) {
        solve(); 
    }
    return 0;
}