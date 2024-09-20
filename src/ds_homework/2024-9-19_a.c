#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char build(char str[], int l , int r) {
    if(str[l] == str[r]) {
        if(l >= r) {
            return '1';
        }
        else {
            return build(str , l+1, r-1);
        }
    }
    else {
        return '0';
    }
}
int32_t main() {
    // int len ;
    // scanf("%d" , &len);
    char str[3000];
    scanf("%3000s" , str);
    printf("%c\n" , build(str , 0 , strlen(str)-1));
}