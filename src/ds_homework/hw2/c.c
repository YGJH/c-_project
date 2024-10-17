// Created on iPad.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack {
    int ch;
    struct stack* front;
    struct stack* next;

}stack;

char st[300];
int nn = 0;
void wr(int a) {
    nn = 0;
    if (a == 0) {
        putchar('0');
        return;
    }
    while (a) {
        st[nn++] = a % 10 + '0';
        a /= 10;
    }
    while (nn) {
        putchar(st[--nn]);
    }
}
void vaild(int a[], int len) {
    stack* head = (stack*)malloc(sizeof(stack));
    head->next = (stack*)malloc(sizeof(stack));
    stack* now = head->next;
    head->front = NULL;
    now->front = head;
    now->ch = -1;
    head->ch = -1;

    int l = 0;
    for (int i = 0; i < len; i++) {
        if (i == a[l]) {
            l++;
            if(now->front->ch != head->ch); {
                now = now->front;
                free(now->next);
            }
            while (now->front != NULL && now->ch != -1) {
                if (now->ch == a[l]) {
                    now = now->front;
                    free(now->next);
                    now->next = NULL;
                    l++;
                }
                else{
                    break;
                }
            }
            now -> next = (stack*)malloc(sizeof(stack));
            now->next->front = now;
            now = now -> next;
        }
        else {
            now->ch = i;
            now->next = (stack*)malloc(sizeof(stack));
            now->next->front=now;
            now = now->next;
            now->ch = -1;
        }
    }
    now = now->front;
    free(now->next);
    while (now->front != NULL && now->ch != -1) {
        if (now->ch == a[l]) {
            now = now->front;
            free(now->next);
            now->next = NULL;
            l++;
        }
        else{
            break;
        }
    }
    if(l != len) {
        for(int i = 0 ; i < len ; i++) wr(a[i]);
        putchar('\n');
    }
    return ;
}
void swap(int* a, int* b) {
    int k = *a;
    *a = *b;
    *b = k;
}

void gen_per(int a[], int l, int r) {
    if (l == r-1) {
        vaild(a, r);
        return;
    }
    else {
        for (int i = l; i < r; i++) {
            swap(&a[i], &a[l]);
            gen_per(a, l + 1, r);
            swap(&a[i], &a[l]);
        }
    }
}
char c;
void re(int* a) {
    *a = 0;
    c = getchar();
    while (c < '0' || c>'9') c = getchar();
    while (c >= '0' && c <= '9') {
        *a = ((*a) << 1) + ((*a) << 3) + (c & 15);
        c = getchar();
    }
    return;
}

int main() {
    int n;
    re(&n);
    int a[n];
    for (int i = 0; i < n; i++) a[i] = i;
    gen_per(a, 0, n);
    return 0;
}