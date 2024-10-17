#include <bits/stdc++.h>
using namespace std;

bool cmp(string &a , string &b) {
    return (a+b) < (b+a);
}

int32_t main() {

    int n;
    cin >> n;
    vector<string> arr;
    string a;
    for(int i = 0 ; i < n ; i++) {
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin() , arr.end() , cmp);

    for(auto I : arr) {
        cout << I;
    }    


    return 0;
}