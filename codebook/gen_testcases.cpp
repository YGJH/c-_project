#include<bits/stdc++.h>
#include<random>
#define pii pair<int,int>
#define pb push_back
using namespace std;
signed main() {
   
  mt19937 now(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<> gen(0  ,1 );
  string s;
  s.pb(1);
  for(int i = 0 ; i < 999 ; i++) {
    if(gen(now)) 
      s.pb('1');
    else
      s.pb('0');
  }
  cout << s << endl;
  cout << 1000 << endl;
  return 0;
}

