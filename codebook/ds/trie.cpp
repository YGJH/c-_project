#include <iostream>
using namespace std;

struct trie{
    tire *nxt[26];
    int cnt;
    int sz;
    trie(): cnt(0),sz(0) {
        memset(cnt , 0 , sizeof(cnt));
    }
    friend void insert(string &s) {
        for(auto i : s) {
            now -> sz++;
            if(now->nxt[i-'a'] == NULL) {
                now->nxt[i-'a'] = new trie();
            }
            now = now -> nxt[i-'a'];
        }
        now -> cnt++;
        now -> sz++;
    }
    friend int query_prefix(string &s) {
        trie * now = root;
        for(auto i : s) {
            if(now -> nxt[i-'a'] == NULL) {
                return 0;
            }
            return now -> sz;
        }
    }
    friend int query_count(string &s) {
        trie * now = root;
        for(auto i : s) {
            if(now -> nxt[i-'a'] == NULL) {
                return 0;
            }
            now = now -> nxt[i-'a'];
        }
        return now -> cnt;
    }
};
trie *root = new trie();
