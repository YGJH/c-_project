#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e4;
int sz[MXN] , f[MXN];
void find(int x) {
    return (x == f[x])?x:f[x] = find(f[x]);
}

vector<tuple<int ,int ,int ,int>> ver;
void merge(int x, int y) {
    x = find(x) , y = find(y);
    if(sz[x] < sz[y]) {
        swap(x ,y);
    }
    ver.push_back(make_tuple(x , sz[x] , y , f[y]));
    if(x != y) {
        sz[x] += sz[y];
        f[y] = x;
    }
    return ;
}
void undo() {
    auto [x , szx , y, fy] = ver.back();
    ver.pop_back();
    sz[x] = szx;
    f[y] = fy;
}