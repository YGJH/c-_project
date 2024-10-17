#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a;
    getline(cin, a);
    stack<char> s;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '(' or a[i] == '[') {
            s.push(a[i]);
        }
        else {
            if ((a[i] != ')' and a[i] != ']') or s.empty() or (a[i] == ']' && s.top() != '[') or (a[i] == ')' && s.top() != '(')) {
                cout << "No" << endl;
                return;
            }
            else {
                s.pop();
            }
        }
    }
    if (s.empty())
        cout << "Yes" << endl;
    else {
        cout << "No" << endl;
    }
    return;
}
bool w = 0; char c;
template<typename T>
inline void re(T& a) {
    c = getchar();	a = 0; while (c < '0' || c > '9') w |= (c == '-'), c = getchar();
    while (c >= '0' && c <= '9') a = (a << 1) + (a << 3) + (c & 15), c = getchar();
    if (w) a = -a;
    return;
}
char st[30]; int kkkk = 0;
template<typename T>
inline void wr(T a) {
    if (a == 0) { putchar('0'); return; }
    if (a < 0)putchar('-'), a = -a;
    while (a) { st[kkkk++] = a % 10 + '0', a /= 10; }
    while (kkkk) { putchar(st[--kkkk]); }
    return;
}
int32_t main() {

    int n;
    re(n);
    while (n--) {
        solve();
    }


}
