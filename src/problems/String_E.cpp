#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int ans = 0;
const int MXN = 1e6+10;
int failure[MXN];
void build_failure(string& w){
    for(int i=1,j=failure[0]=-1;i<w.length();i++){
        while(j>=0 && w[i] != w[j+1]){ //當不相同無法匹配
            j = failure[j];
        }
        if(w[i] == w[j+1]){ // 如果可以加長長度，則為前一個答案+1
            ++j;
        }
        failure[i] = j; // 紀錄答案
    }
}
void KMP(string s, string w){
    // i 為字串 s 當前 index, j 為字串 w 以匹配到的 index
    for(int i = 0,j = -1; i < s.length(); ++i){
        while(j >= 0 && s[i] != w[j+1]){ // 當匹配失敗找到次長相同前綴後綴，移動字串W
            j = failure[j];
        }
        if(s[i] == w[j+1]){ // 當字元相等
            ++j;
        }
        if(j+1 == w.length()){ //  當字串完全匹配
            // ans.push_back(i-w.size()+1); // 加進答案
            ans++;
            j = failure[j]; // 移動字串W
        }
    }
}
int i;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    string cm;
    cin >> str;
    cin >> cm;
    // if(str.length() < cm.length()) {
    //     swap(str , cm);
    // }
    build_failure(cm);
    KMP(str ,cm);    
    cout << ans << endl;
    return 0;
}