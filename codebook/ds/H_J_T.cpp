#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
    ll val;
    node *l, *r;
};
void add_ver(int x, int v)
{
    ver.push_back(update_ver(ver.back(), 0, n - 1, x, v));
}

vector<node *> ver; //用一個vertor紀錄全部版本的根節點
void build(node *now_ver, node *l, node *r) {}
// val 儲存當前節點的數量
ll query(node *now_ver, node *l, node *r, node *ql, node *qr)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    if (x->l->val <= k)
        return query(x->l, l, mid, k);
    else
        return query(x->l, mid + 1, r, k - x->l->val);
}
ll query(node * pre , node *now , int l , int r , int k) {
    if(l == r)  return l;
    int mid = (l+r)>>1;
    int l_num = now->l->val - pre->l->val;
    if(k <= l_num) return query(pre->l, now->l , l , mid , k);
    else           return query(pre->l, now->l , mid+1 , r, k - l_num);
}
node *update_ver(node *pre_ver, int l, int r, int pos, int v)
{
    node *x = new node();
    if (l == r)
    {
        x->val = v;
        return x;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
    {
        x->l = update(pre_ver->l, x->l, l, mid, pos, v); // 左邊節點連項新節點
        x->r = pre_ver->r; // 右邊連到原本的右邊
    }                      //更新左邊
    else
    {
        x->l = pre_ver->l; // 左邊連到原本的左邊
        x->r =
            update(pre_ver->r, x->r, mid + 1, r, pos, v); // 右邊節點連向新結點
    }                                                     //更新右邊
    x->val = x->l->val + x->r->val return x;
} // 回傳新建的節點
void add_ver(int x, int v)
{
    ver.push_back(update_ver(ver.back(), 0, n - 1, x, v));
} // 修改位置x的值為v
