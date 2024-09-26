#include <stdio.h>
#include <stdlib.h>
typedef struct node node;
typedef struct node{
    double cof;
    int expn;
};

void bubbleSort(node arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].expn < arr[j + 1].expn) {
                node temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

signed main() {
    // int NUMBER_TERMS;
    // node *head = (node*)malloc(sizeof(node));
    int sz;
    node tmp[10000];
    int now = 0;
    while(scanf("%d\n" , &sz) != EOF) {
        // printf("%d\n" , sz);
        int tmpp = now;
        for(int i = 0 ; i < sz ; i++) {
            scanf("%lf " , &tmp[now++].cof);
        }
        now = tmpp;
        for(int i = 0 ; i < sz ; i++) {
            scanf("%d " , &tmp[now++].expn);
        }
    }
    bubbleSort(tmp , now);
    node ans[1000];
    int cou = 0;
    ans[cou++]=tmp[0];
    for(int i = 1 ; i < now ; i++) {
        if(ans[cou-1].expn == tmp[i].expn) {
            ans[cou-1].cof += tmp[i].cof;
        }
        else{
            ans[cou++] = tmp[i];
        }
    }
    printf("%d\n" , cou);
    for(int i = 0 ; i < cou ; i++) {
        printf("%lf " , ans[i].cof);
    }

    putchar('\n');
    for(int i = 0 ; i < cou ; i++) {
        printf("%d " , ans[i].expn);
    }
    return 0;
}