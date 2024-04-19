#include<bits/stdc++.h>
#include<random>
#define pii pair<int,int>
#define pb push_back
using namespace std;
signed main() {
  const int node = 6;
  mt19937 now(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<> gen(1, node);
  cout << node  + 2 << endl;
map<pii ,int> con;
  for(int i = 0 ; i < node + 2 ; i++ ) {
      int tmp1 = gen(now) ; int tmp2 = gen(now);
      int val = gen(now);
      while(con[{tmp1 , tmp2}] || tmp1 == tmp2 ) {
        tmp1 = gen(now);
        tmp2 = gen(now);
      }
    cout << tmp1 << ' ' << tmp2  << ' ' << val << endl;
  }
  const int q = 5;
  cout << q << endl;
  for(int i = 0 ; i < q ; i++ )  {
    int tmp1 = gen(now) , tmp2 = gen(now);
    cout << tmp1 << ' ' << tmp2 << endl;
  }
  return 0;
}

