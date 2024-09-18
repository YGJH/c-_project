#include <stdio.h>
#include <stdlib.h>

int A(int m , int n) {
     if(m ==0){
        return n+1;
     }
     else if(n == 0) {
        return A(m-1 , 1);
     }
     else {
        return A(m-1 , A(m , n - 1));
     }
}

signed main() {
    printf( "A(3 ,3) = %d\n",A(3 , 3));
    return 0;
}