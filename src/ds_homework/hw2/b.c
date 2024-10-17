#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define max(a,b) (a>b)?a:b
#define mxn 1001
typedef struct {
    int row, col, val;

}node;
bool w = 0; char c;
void re(int(*a)) {
    w = 0;
    c = getchar();	*a = 0; while (c < '0' || c > '9') w |= (c == '-'), c = getchar();
    while (c >= '0' && c <= '9') (*a) = ((*a) << 1) + ((*a) << 3) + (c & 15), c = getchar();
    if (w) *a = -(*a);
    return;
}
char st[30]; int kkkk = 0;
void wr(int a) {
    if (a == 0) { putchar('0'); return; }
    if (a < 0)putchar('-'), a = -a;
    while (a) { st[kkkk++] = a % 10 + '0', a /= 10; }
    while (kkkk) { putchar(st[--kkkk]); }
    return;
}
void read_mat(node mat[]) {
    re(&mat[0].row);
    re(&mat[0].col);
    re(&mat[0].val);
    for (int i = 1; i <= mat[0].val; i++) {
        re(&mat[i].row);
        re(&mat[i].col);
        re(&mat[i].val);
    }
}

void print_mat(node mat[]) {
    int now = 1;
    for (int i = 0; i < mat[0].row; i++) {
        for (int j = 0; j < mat[0].col; j++) {
            if (mat[now].row == i
                && mat[now].col == j) {
                wr(mat[now++].val);
            }
            else {
                putchar('0');
            }
            if (j != mat[0].col - 1) {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}
int search(node mat[], int val) {
    for (int i = 1; i <= mat[0].val; i++) {
        if (mat[i].val == val) {
            return 1;
        }
    }
    return -1;
}

void swap(node* a, node* b) {
    node c;
    c.row = a->row;
    c.col = a->col;
    c.val = a->val;
    a->row = b->col;
    a->col = b->row;
    a->val = b->val;
    b->row = c.row;
    b->col = c.col;
    b->val = c.val;
}

void fast_transpose(node a[], node b[]) {
    int ro[mxn];
    memset(ro, 0, sizeof(ro));
    for (int i = 1; i <= a[0].val; i++) {
        ro[a[i].col]++;
    }
    int tim = 0, timm=0;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;
    timm = ro[0];
    ro[0] = 1;
    for(int i = 1 ; i <= a[0].col ; i++) {
        tim = ro[i];
        ro[i] = ro[i-1]+timm;
        timm = tim;
    }
    int now;
    for (int i = 0; i <= a[0].val; i++) {
        now = ro[a[i].col]++;
        b[now].col = a[i].row;
        b[now].row = a[i].col;
        b[now].val = a[i].val;
    }
}

signed main() {
    node mat[mxn];
    read_mat(mat);
    print_mat(mat);
    // wr(search(mat, 2));
    putchar('\n');
    // wr(search(mat, -2));
    node b[mxn];
    fast_transpose(mat, b);
    print_mat(b);

}