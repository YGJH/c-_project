#include <bits/stdc++.h>
using namespace std;
int main() {
    while(1) {
        system("./gen_testcases > input.out");
        system("./ac < input.out > a.out");
        system("./ola < input.out > b.out");
        // system("cat input.out");
        // system("cat a.out");
        // system("cat b.out");
        FILE * ac = fopen("a.out" , "r");
        FILE * wa = fopen("b.out" , "r");
        char tmp[300], tmp2[300] ;
        fread(tmp , 1 , sizeof(tmp) , ac);
        fread(tmp2 , 1 , sizeof(tmp2) , wa);
        int now = 0;
        bool ok = true;
        while(now < 300 && tmp[now] != '\0' && tmp2[now] != '\0') {
            if(tmp[now] != tmp2[now]) {
                ok = false;
                break;
            }
            now++;
        }
        if(!ok) {
            system("cat input.out");
            system("cat a.out");
            system("cat b.out");
            fgetc(stdin);
            fgetc(stdin);
        }
    }

}