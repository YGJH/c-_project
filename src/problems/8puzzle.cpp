#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ishowspeed cin.tie(),cout.tie(),ios_base::sync_with_stdio(0)
using namespace std;
unordered_map<string ,int> mp;

int cas = 1;
string ans = "123456780";
void solve() {
    mp.clear();
    queue<pair<string , int>> que;
    que.push(mk(ans, 0));

    while(que.empty() == 0) {
        int total = que.size(); 
        while(total--) {

            auto now = que.front();
            que.pop();
            if(mp[now.first] != 0) {continue;}
            else {
                mp[now.first] = now.second;
                int ze;
                for(int i = 0 ; i < 9 ; i++) {
                    if(now.first[i] == '0') {
                        ze = i;
                        break;
                    }
                }

                if(ze - 3 >= 0 ) {
                    string tmp(now.first);
                    swap(tmp[ze] , tmp[ze-3]);
                    if(mp[tmp] == 0)  {
                        que.push(mk(tmp , now.second + 1));
                    }
                }
                // left
                if(  ( ze % 3 )  > 0 ) {
                    string tmp(now.first);
                    swap(tmp[ze] , tmp[ze - 1]);
                    if(mp[tmp] == 0) {
                        que.push(mk(tmp , now.second+1));
                    } // 0 1 2 3 4 5 6 7 8
                }     // 0 1 2 0 1 2 0 1 2
                // down
                if(ze + 3 <= 8) {
                    string tmp(now.first);
                    swap(tmp[ze] , tmp[ze + 3]);
                    if(mp[tmp] == 0) {
                        que.push(mk(tmp , now.second + 1));
                    }
                }
                // right
                if((ze % 3) < 2) {
                    string tmp(now.first);
                    swap(tmp[ze] , tmp[ze+1]);
                    if(mp[tmp] == 0) {
                        que.push(mk(tmp , now.second + 1));
                    }
                }
        
            }
        }
    }
}



int main() {
    ishowspeed;
    int a;
    cin >> a;
    thread solve();
    for(int i = 0 ; i < a ; i++) {
        string in = "000000000";
        for(int p = 0 ; p < 9 ; p++) {
            int k;
            cin >> k;
            in[p] = k + '0';
        }
            if(mp[in] != 0) {
                cout << "Case " << cas++ << ": " << mp[in] << endl;
            }
            else {
                cout << "Case " << cas++  << ": " << "impossible" << endl;
            }
    }
    return 0;
}