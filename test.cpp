#include <bits/stdc++.h>
using namespace std;
#define max(a,b) (a > b ? a : b)
signed main() {

    int i = 0 , cnt = 0;
    vector<int> num;
    int tmp;
    while(cin >> tmp) num.push_back(tmp); ;
    for(; i < num.size() ; i++) {
        if(num[i] < num.size() && num[i] >= 0) {
            swap(num[i], num[num[i]]);
        }
    }
    for(i = 1 ; i < num.size() ; i++) {
        cout << num[i] << ' ';
        if(num[i] != i) {
            cout << i << endl;
            return 0;
        }
    }
    cout << i << endl;

    return 0;
}
