#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define int long long
struct trie{
    trie * nxt[26];
    int sz;
    int nxt_step;
    int cnt ;
    int this_size;
    trie(): sz(0), cnt(0) , nxt_step(0) , this_size(0) {
        memset(nxt , 0 , sizeof(nxt));
    }
};
trie * root = new trie;
int i;
int q;
int n ;
string tmp;
string tmp2;
void insert(string &s) {
    trie * now = root;
    for(auto i : s) {
        now->sz++;
        if(now->nxt[i-'a'] == NULL) {
            now -> nxt[i - 'a'] = new trie;
        }
        now = now -> nxt[i-'a'];
    }
    now->sz++;
    now->cnt++;
}
int kk;
string ans2;
void dfs(trie*now) {
    // while(now -> cnt != now -> this_size)
    while(now->nxt_step != -1) {
        ans2.pb(now->nxt_step + 'a');
        now = now->nxt[now->nxt_step];
        // cerr << ans2 << endl;
    }
    kk = now->cnt;
    return;
}

string ans;
void query_prefix(string &s) {
    trie * now = root;
    ans.clear();
    for(auto i : s) {
        if(now -> nxt[i-'a'] == NULL) {
            return;
        }
        ans.pb(i);
        now = now -> nxt[i-'a'];
    }
    // cerr << "ans: " << ans << endl;
    dfs(now);
}

unordered_map<string , int> mp;
int build(trie * now) {
    int mx_occurance = -1;
    bool en = 1;
    bool enn = 0;
    if(mp[tmp]) {
        enn = 1;
        mx_occurance = mp[tmp];
        now->nxt_step = -1;
        now->this_size = mx_occurance;
    }
    // cerr << tmp << endl;
    for(int i = 0 ; i < 26 ; i++) {
        if(now->nxt[i] != NULL) {
            tmp.pb(i+'a');
            en = 0;
            auto tmp3 = build(now->nxt[i]);
            tmp.pop_back();
            // cerr << mx_occurance << ' ' << tmp3 << endl;
            if(mx_occurance < tmp3) {
                mx_occurance = tmp3;
                now->nxt_step = i;
                now->this_size = tmp3;
            }
        }
    }
    // cerr << tmp << ' ' << now->cnt << endl;
    // cerr << now->nxt_step << endl;
    if(!en)
        return now->this_size;
    else 
        return mp[tmp];
}
void dfs_test(trie * now) {
    for(int i = 0 ; i < 26 ; i++) {
        if(now->nxt[i] != NULL) {
            tmp.pb(i+'a');
            dfs_test(now->nxt[i]);
            tmp.pop_back();       
        }
    }
    cout << tmp << ' ' << now->nxt_step << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i = 0 ; i < n ; i++) {
        cin >> tmp2;
        mp[tmp2]++;
        insert(tmp2); 
    }
    build(root);
    // tmp.clear();
    // dfs_test(root);
    cin >> q;
    for(int i = 0 ; i < q ; i++) {
        cin >> tmp2;
        kk = 0;
        query_prefix(tmp2);
        if(kk) {
            cout << ans ;
            cout << ans2 << ' ' << kk << endl;
            ans2.clear();
        }
        else {
            cout << -1 << endl;
        }
    }
}