#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct team{
    int mx_win;
    int of , de;
    int st_of , st_en;
};

string player[300];
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    queue<int> que;
    for(int i = 0 ; i < n ; i++) {
        cin >> player[i];
        que.push(i);
    }
    int mx = 0;
    vector<team> win;
    string soc ; 
    cin >> soc;
    team wh;
    team bla;
    wh.of = que.front(); que.pop();
    bla.of = que.front(); que.pop();
    wh.de = que.front();  que.pop();
    bla.de = que.front() ; que.pop();
    bla.mx_win = 0;
    wh.mx_win = 0 ;
    wh.st_of = 0 ;
    wh.st_en = 1;
    bla.st_of = 0;
    bla.st_en = 1;
    int cou = 3;
    for(int i = 0 ; i < soc.length() ; i++) {
        if(soc[i] == 'W') {
            que.push(bla.de);
            swap(bla.st_en , bla.st_of);
            swap(bla.of ,bla.de);
            bla.of = que.front(); que.pop();
            bla.st_of = cou++;
            bla.mx_win = 0;
            wh.mx_win++;
            mx = max(mx , wh.mx_win);
            win.push_back(wh);
            swap(wh.of , wh.de);
            swap(wh.st_en , wh.st_of);
        }
        else if(soc[i] == 'B'){
            que.push(wh.de);
            swap(wh.de , wh.of);
            swap(wh.st_en , wh.st_of);
            wh.st_of = cou++;
            wh.of = que.front() ; que.pop();
            wh.mx_win = 0;
            bla.mx_win++;
            mx = max(bla.mx_win , mx);
            win.push_back(bla);
            swap(bla.de , bla.of);
            swap(bla.st_en , bla.st_of);
        }
    }
    // map<pair<int,int>, bool> mp;
    for(auto &a : win) {
        if(a.mx_win >= mx) {
            if(a.st_en > a.st_of) {
                cout << player[a.of] << ' ' << player[a.de] << endl;
            } else {
                cout << player[a.de] << ' ' << player[a.of] << endl;
            }

        }
    }
    return 0;

}