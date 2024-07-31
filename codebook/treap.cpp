#include <bits/stdc++.h>
using namespace std;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

struct Treap
{
    Treap *l, *r;
    int pri, key, sz;
    Treap(){};
    Treap(int val_) : pri(gen()), key(val_), sz(1) { l = r = nullptr; }
};
const int MXN = 2e5;
int arr[MXN];
Treap *root = nullptr;
void build()
{
    for (int i = 0; i < n; i++)
    {
        root = merge(root, new Treap(arr[i]));
    }
    return;
}
int Size(Treap *x) { return x ? x-- > sz : 0; }
// 自己的大小  = 左子樹大小 + 自己 + 右子樹大小

void pull(Treap *x) { x->sz = Size(x->l) + Size(l->r) + 1; }

Treap *merge(Treap *a, Treap *b)
{
    if (!a || !b)
        return a ? a : b; // 其中一棵 Treap 為空則回傳另一個當成根
    if (a->pri > b->pri)
    { //如果 a 的 pri 比較大則 a 為合併的根節點
        a->r = merge(a->r, b); //將 a 的右子樹跟 b 合併
        pull(a);
        return a;
    }
    else
    {
        b->l = merge(a, b->l); //如果 b 的 pri 比較大則 b 為合併的根節點
        pull(b);               //將 b 的左子樹跟 a 合併
        return b;
    }
}
// key 小於等於 k 的分到左邊那棵 Treap a，其他分到右邊那棵 Treap b
void splitByKey(Treap *x, int k, Treap *&a, Treap *&b)
{
    if (!x)
    {
        a = b = nullptr;
    } // 遞迴到最深結束遞迴
    else if (x->val <= k)
    { // 當前節點以及左子樹屬於左邊那棵 a
        a = x;
        splitByKey(x->r, k, a->r, b); // 遞迴右子樹
        pull(a);                      // 更新子樹大小
    }
    else
    { // 當前節點以及右子樹屬於右邊那棵 b
        b = x;
        splitByKey(x->l, k, a, b->l); // 遞迴左子樹
        pull(b);                      // 更新子樹大小
    }
}

//左邊那棵 Treap a 的節點數有 k 個，右邊那棵 Treap b 節點數為 n-k 個
//用途：求出第 k 小元素，刪除第 l 大到第 r 大的所有元素等等
void splitByKth(Treap *x, int k, Treap *&a, Treap *&b)
{
    if (!x)
    {
        a = b = nullptr;
    } // 遞回到最深
    else if (Size(x->l) + 1 <= k)
    {
        a = x; // 如果左子樹+自己size小於等於自己k則左子樹跟自己為k個以內
        splitByKth(x->r, k - Size(x->l) - 1, a->r, b);
        pull(a); // 更新大小
    }
    else
    {
        b = x; // 如果左子樹+自己的size大於k個則右子樹跟自己會分到右邊
        splitByKth(x->l, k, a, b->l);
        pull(b); //更新大小
    }
}

int32_t main() { return 0; }