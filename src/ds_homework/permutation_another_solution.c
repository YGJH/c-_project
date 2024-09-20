#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;
int check(char *s , int l , int p, char k) {
    for(int i = l ; i < p ; i++) {
        if(k == s[i]) {
            return 0;
        }
    }
    return 1;
}
void swap(char *a , char *b) {
    char temp = *b;
    *b = *a;
    *a = temp;
    return ;
}
int per(char *s , int l , int r) {
    int ret = 0;
    if(l>=r-1) {
        printf("%s\n" , s);
        return 1;
    }
    for(int i = l ; i < r ; i++) {
        if(check(s, l , i , s[i])) {
            swap(&s[i] , &s[l]);
            ret += per(s , l+1 , r);
            swap(&s[i] , &s[l]);
        }
    }
    return ret;
}
int main() {
    char str[3200];
    scanf("%3000s" , str);
    printf("%d" , per(str , 0 , strlen(str)));
}