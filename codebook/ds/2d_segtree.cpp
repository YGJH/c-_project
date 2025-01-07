#include <bits/stdc++.h>
using namespace std;
#define cl(x) (x << 1) + 1
#define cr(x) (x << 1) + 2

int seg[16 * n * m];
struct SEG
{
    void build_y(int idx, int idy, int lx, int rx, int ly, int ry)
    {
        if (ly == ry)
        {
            tree[idx][idy] = arr[lx][ly];
            return;
        }
        int my = (ly + ry) >> 1;
        build_y(idx, cl(idy), lx, rx, ly, my);
        build_y(idx, cr(idy), lx, rx, my + 1, ry);
        tree[idx][idy] = tree[idx][cl(idy)] + tree[idx][cr(idy)];
    }
    void build_x(int idx, int lx, int rx)
    {
        if (lx != rx)
        {
            int mx = (l + r) >> 1;
            build_x(cl(idx), lx, mx);
            build_x(cr(idx), mx + 1, rx);
        }
        build_y(idx, 0, lx, rx, 0, m - 1);
    }
    int query_y(int idx, int idy, int ly, int ry, int qly, int qry)
    {
        if (qly <= ly && ry <= qry)
        {
            return tree[idx][idy];
        }
        int my = (ly + ry) >> 1, ret = 0;
        if (qy <= my)
            ret += query_y(idx, cl(idy), ly, my, qly, qry);
        if (qy > my)
            ret += query_y(idx, cr(idy), my + 1, ry, qly, qry);
        return ret;
    }
    int query_x(int idx, int lx, int rx, int qlx, int qly, int qrx, int qry)
    {
        if (qlx <= lx && rx <= qrx)
        {
            return query_y(idx, 0, 0, m - 1, qly, qry);
        }
        int mx = (lx + rx) >> 1, ret = 0;
        if (qlx <= mx)
            ret += qeury_x(cl(idx), lx, mx, qlx, qly, qrx, qry);
        if (qrx > mx)
            ret += query_x(cr(idx), mx + 1, qrx, qlx, qly, qrx, qry);
        return ret;
    }
    void update_y(int idx, int idy, int lx, int rx, int ly, int ry, int qy,
                  int val)
    {
        if (ly == ry)
        {
            if (lx == rx)
                tree[idx][idy] = val;
            else
                tree[idx][idy] = tree[cl(idx)][idy] + tree[cr(idx)][idy];
            return;
        }
        int my = (ly + ry) / 2;
        if (qy <= my)
            update_y(idx, cl(idy), lx, rx, ly, my, qy, val);
        else
            update_y(idx, cr(idy), lx, rx, my + 1, ry, qy, val);
        tree[idx][idy] = tree[idx][cl(idy)] + tree[idx][cr(idy)];
    }
    void update_x(int idx, int lx, int rx, int qx, int qy, int val)
    {
        if (lx != rx)
        {
            int mx = (lx + rx) / 2;
            if (qx <= mx)
                update_x(cl(idx), lx, mx, qx, qy, val);
            else
                update_x(cr(idx), mx + 1, rx, qx, qy, val);
        }
        update_y(idx, 0, lx, rx, 0, m - 1, qy, val);
    }
    void build(int idx, int idy, int lx, int ry, int lx, int ry)
    {
        build_y(idx, idy, lx, rx, ly, ry);
        build_x(idx, lx, rx);
    }
    void update(int idx, int idy, int lx, int ry, int lx, int ry, int pos,
                int val)
    {
        void update_y(int idx, int idy, int lx, int rx, int ly, int ry, int qy,
                      int val);
        void update_x(int idx, int lx, int rx, int qx, int qy, int val);
    }
    int query(int idx, int idy, int lx, int ry, int lx, int ry)
    {
        query_y(int idx, int idy, int ly, int ry, int qly, int qry);
        query_x(int idx, int lx, int rx, int qlx, int qly, int qrx, int qry);
    }
};

int32_t main() { return 0; }