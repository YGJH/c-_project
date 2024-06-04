#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
struct TRIE {
    TRIE *nxt[26];
    int cnt;
    int sz;
    int big;
    char best;
    TRIE():cnt(0), sz(0), big(0), best('z') {
        memset(nxt, 0, sizeof(nxt));
    }
};
TRIE *root = new TRIE();
void insert(string& str) {
    TRIE *now = root;
    for (auto i : str) {
        now -> sz++;
        if (now -> nxt[i - 'a'] == NULL) {
            now -> nxt[i - 'a'] = new TRIE();
        }
        now = now -> nxt[i - 'a'];
    }
    now -> cnt++;
    now -> sz++;
    now -> big = max(now -> big, now -> cnt);
}
pair<int, string> query(string& s) {
    TRIE *now = root;
    string path = s;
    for (char i : s) {
        if (now -> nxt[i - 'a'] == NULL) return {-1, "1"};
        now = now->nxt[i - 'a'];
    }

    while((now -> cnt) != (now -> big)) {
        path += now->best;
        now = now->nxt[now->best - 'a'];
    }
    return {now->cnt, path};
}
void dfs(TRIE* now, TRIE* fa, char cur) {
    for (int i = 0; i < 26; i++) {
        if (now->nxt[i] == NULL) continue;
        dfs(now->nxt[i], now, i + 'a');
        if (now->big < now->nxt[i]->big) {
            now->big = now->nxt[i]->big;
            now->best = i + 'a';
        } else if (now->big == now->nxt[i]->big) {
            now->best = min((char)(i + 'a'), now->best);
        }
    }
}
int n, q;
string str;
signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        insert(str);
    }   

    dfs(root, NULL, 'a');
    cin >> q;
    for (int ll = 0; ll < q; ll++) {
        cin >> str;
        auto it = query(str);
        if (it.F == -1) {
            cout << -1 << '\n';
            continue;
        }
        cout << it.S << ' ' << it.F << '\n';
    }
}