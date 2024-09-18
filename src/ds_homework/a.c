#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int coeff;
    int level;
    struct pol * nxt;
}pol;

pol* head;

int horner(pol* n , int x , int val) {
    printf("val = %d\n" , val);    
    return (n->nxt && n->level != 0) ? horner(n->nxt , x , (val + n->coeff)*x ) : n->coeff+val;
}

int main(){
    int n;
    scanf("%d\n" , &n);
    
    head = (pol*)malloc(sizeof(pol));
    
    pol* tmp;
    tmp = head;
    tmp->nxt = NULL;
    for(int i = n ; i >= 0 ; i--) {
        int v ; 
        scanf("%d " , &v);
        if(tmp->nxt == NULL) tmp->nxt = (pol*)malloc(sizeof(pol));
        tmp = tmp->nxt;
        tmp->coeff = v;
        tmp->level = i;
        printf("i = %d\n" , i);
        tmp->nxt = NULL;
    }
    int x;
    scanf("%d" , &x);
    printf("ans = %d\n" , horner(head->nxt ,x , 0 ));
}