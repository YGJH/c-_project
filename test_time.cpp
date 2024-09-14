#include <bits/stdc++.h>
using namespace std;

int main() {
    // bool a = 0;
    // auto st = chrono::high_resolution_clock::now();
    // for(int i = 0 ; i <= 3e9 ; i++) {
    //     a=true;
    // }
    // auto en = chrono::high_resolution_clock::now();
    // chrono::duration<double> dur = en - st;
    // cout << "block 1: " << dur.count() << endl;
    
    // bool v = 0;
    // st = chrono::high_resolution_clock::now();
    // for(int i = 0 ; i <= 3e9 ; i++) {
    //     v^=true;
    // }
    // en = chrono::high_resolution_clock::now();
    // dur = en - st;
    // cout << "block 2: " << dur.count() << endl;

    string s;
    auto st = chrono::high_resolution_clock::now();
    for(int i = 0 ; i < 1e9 ; i++) {
        s.push_back('s');
        s.pop_back();
    }
    auto en = chrono::high_resolution_clock::now();
    chrono::duration<double> dur = en - st;
    cout << dur.count() << endl;
    st = chrono::high_resolution_clock::now();
    for(int i = 0 ; i < 1e9 ; i++) {
        s+='s';
        s.pop_back();
    }
    en = chrono::high_resolution_clock::now();
    dur = en - st;
    cout << dur.count() << endl;
    

}