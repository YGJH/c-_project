#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;
typedef struct node node;
struct node{
    long long a;
    long long b;
};
node head[10000000];
const long long ha1 =75577;
const long long ha2 = 12721;
const long long mod1 = 998244353;
const long long mod2 = 606894023;
int sz = 0;
int len = 0;
void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

int check(node *x) {
    for(int i = 0 ; i < count ; i++) {
        if(head[i].a == x->a && head[i].b == x->b)
            return 0; 
    }
    return 1;
}
void gen_hash(char *x , node*ret) {
    ret->a = 0;
    ret->b = 0;
    for(int i = 0 ; i < len ; i++) {
        ret->a = (ret->a * ha1 + x[i]);
        ret->a %= mod1;
        ret->b = (ret->b * ha2 + x[i]);
        ret->b %= mod2;
    }
    return;
}
int push(char *x) {
    node tmp;
    gen_hash(x , &tmp);
    if(!check(&tmp)) return 0;
    head[count++] = tmp;
    return 1;
}
void permutation(char* str, int idx, int n) {
    if (idx == n - 1) {
        if(push(str))
            printf("%s\n", str);
        return;
    }
    for (int i = idx; i < n; i++) {
        swap(&str[idx], &str[i]);
        permutation(str, idx + 1, n);
        swap(&str[idx], &str[i]);
    }
}
int main() {
    char str[100];
    scanf("%100s" , str);
    len = strlen(str);
    permutation(str , 0 , len);
    printf("%d\n" , count);
    return 0;
}