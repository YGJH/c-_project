#include <bits/stdc++.h>
using namespace std;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

struct Treap
{
    Treap *l, *r;
    int pri, key, sz , mn;
    Treap(){};
    Treap(int val_) : pri(gen()), key(val_), sz(1) { l = r = nullptr; }
    /*
    最小值的
    Treap(int val_) : pri(gen()), key(val_), mn(val_) , sz(1) { l = r = nullptr; }
    */
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
/*
以下兩個都是用來找最小值時用到的
int getMn(Treap *x) { return x ? x->mn : 0;}
void pull(Treap *x) {
    x->sz = Size(x->l) + Size(x->r) + 1;
    x->mn = min(min(getMn(x->l) , getMn(x->r)) , x->key);
}

求[L, R]區間內最小值
void getMin() {
    Treap *l , *m , *r;
    splitByKth(root , R , l , r);
    splitByKth(l , L-1 , l , m);
    cout << m->mn << endl;
    //合併回去
    root = merge(l , merge(m , r));
}
*/

// 自己的大小  = 左子樹大小 + 自己 + 右子樹大小
int Size(Treap *x) { return x ? x -> sz : 0; }

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

/*
再新增打大小為x的元素時需要先把Treap分成兩半，一半小於等於x一半打於x
如此以來即可使用merge()合併
*/
void insert(int x)
{
    Treap *left, *right;
    splitByKey(root, x, left, right);
    root = merge(left, merge(new Treap(x), right));
    return;
}
/*
Treap 中刪除一個值為x的元素
splitByKey 分成兩堆 Treap l (<= x) 以及 Treap r (> x) 的
splitByKey 把 l 再分成兩堆 Treap l (< x) 以及 Treap m (= x) 的
這時我們就有三個樹堆 < x, = x, > x
如果要刪除全部值為 x 的元素，則直接 root = merge(l, r)
只刪除一個值為 x 的元素用以下寫法，合併 l (< x), r(> x), m 的左右子樹
即為只刪除一個元素而已
root = merge(merge(l, merge(m->l, m->r)), r)
*/
void erasse()
{
    Treap *l, *mid, *r;
    splitByKey(root, val, l, r); // 把小於等於val的丟到l
    splitByKey(l, val - 1, l, mid); // 小於val的丟到l , 等於val 的就會在mid裡
    root = merge(merge(l, merge(m->l, m->r, )), r); // 將除了節點 m 以外的合併
}

/*
修改第i個位置的值成x
*/
void addjust(int i , int x) {
    Treap* l , *m , *r;
    splitByKth(root , i , l , r);
    splitByKth(l , i-1 , l , m);
    m->key = m -> mn = x;
    root = merge(l , merge(m , r));
}

int32_t main() { return 0; }