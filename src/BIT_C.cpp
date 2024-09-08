#include <bits/stdc++.h>
using namespace std;

struct BIT
{
    vector<long long> bit;
    int n;
    inline long long lowbit(long long x) { return x & -x; }
    void build(int n_)
    {
        n = n_ + 1;
        bit = vector<long long>(n, 0);
        return;
    }
    long long query(int pos)
    {
        long long ret = 0;
        for (; pos; pos -= lowbit(pos))
        {
            ret += bit[pos];
        }
        return ret;
    }
    void update(int pos, int val)
    {
        for (; pos < n; pos += lowbit(pos))
        {
            bit[pos] += val;
        }
        return;
    }
};

struct Pt
{
    int x, y;
};
void solve()
{
    int n, k;
    cin >> n >> k;
    // BIT tre1;
    BIT tre2;
    // tre1.build(n);
    tre2.build(n);
    vector<Pt> node(n);
    // vector<int> node_x2(n);
    vector<int> node2(n);

    for (int i = 0; i < n; i++)
    {
        cin >> node[i].x >> node[i].y;
        // node_x2[i] = node_x[i];
        node2[i] = node[i].y;
    }
    auto cmp = [](Pt &a, Pt &b) -> bool { return a.x < b.x; };
    // sort(node_x.begin() , node_x.end());
    // node_x.erase(unique(node_x.begin() , node_x.end()), node_x.end());
    sort(node.begin(), node.end(), cmp);
    // node.erase(unique(node.begin() , node.end()), node.end());
    sort(node2.begin(), node2.end());
    node2.erase(unique(node2.begin(), node2.end()), node2.end());
    // for(auto &p : node_y) {
    //     cout << p << endl;
    // }
    for (int i = 0; i < n; i++)
    {
        // node_x2[i] = lower_bound(node_x.begin(), node_x.end() , node_x2[i]) -
        // node_x.begin() + 1;
        node[i].y = lower_bound(node2.begin(), node2.end(), node[i].y) -
                    node2.begin() + 1;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int a = tre2.query(node[i].y);
        // tre1.update(node_x2[i] , 1);
        tre2.update(node[i].y, 1);
        // cerr << a << ' ' << b << endl;
        if (abs((n - a - 1) - a) >= k)
        {
            count++;
        }
    }
    cout << count << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}