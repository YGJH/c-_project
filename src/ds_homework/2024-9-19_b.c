#include <stdio.h>
#include <stdlib.h>

int GCD(int a , int b) {
    return (b) ? GCD(b , a%b) : a;
}

int32_t main() {
    int a , b;
    scanf("%d %d" , &a , &b);
    printf("GCD = %d" , GCD(a ,b));
}