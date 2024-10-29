#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


char st[30]; int kkkk = 0;
void wr(int a) {
    kkkk = 0;
    if (a == 0) { putchar('0'); return; }
    if (a < 0)putchar('-'), a = -a;
    while (a) { st[kkkk++] = a % 10 + '0', a /= 10; }
    while (kkkk) { putchar(st[--kkkk]); }
    return;
}
void initArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = 0;
    }
    return ;
}
int isEmpty(int arr[], int len) {
    for (int i = 0; i < len; i++)
        if (arr[i] != 0) return 0;
    return 1;
}
int printSubset(int arr[], int choice[], int len) {
    for (int i = 0; i < len; i++) {
        if (choice[i] == 1) wr(arr[i]),putchar(' ');
    }
    putchar('\n');
}

void subsetGen(int arr[] , int l , int r, int choice[]) {
    if(l>=r) {
        if(isEmpty(choice , r+1)) puts("empty set");
        else printSubset(arr , choice , r+1);
        return ;
    }
    choice[l] = 1;
    subsetGen(arr , l + 1, r , choice);
    choice[l] = 0;
    subsetGen(arr , l + 1, r , choice);
}
int main() {

    int i = 0;
    int arr[28] , choice[28];
    puts("Input integer list (up to 20 integers): ");
    while (scanf("%d", &arr[i++]) != EOF);
    initArray(choice  , i);
    subsetGen(arr , 0 , i-1 , choice);

    return 0;
}