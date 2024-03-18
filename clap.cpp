#include <bits/stdc++.h>
using namespace std;
int main() {
    while(1) {
        system("./gen_testcases > input.out");
        system("./ac < input.out > a.out");
        system("./dpondag1 < input.out > b.out");
        FILE * ac = fopen("a.out" , "r");
        FILE * wa = fopen("b.out" , "r");
        char tmp[3000], tmp2[3000] ;
        fseek(ac , 0 , SEEK_END);
        int len1 = ftell(ac);
        fseek(wa , 0 , SEEK_END);
        int len2 = ftell(wa);
        rewind(ac);
        rewind(wa);
        fread(tmp , 1 , len1 , ac);
        fread(tmp2 , 1 , len2 , wa);
        int now = 0;
        bool ok = true;
        while(now < len1) {
            if(tmp[now] != tmp2[now]) {
                ok = false;
                break;
            }
            now++;
        }
        fclose(ac);
        fclose(wa);

        if(!ok) {
            system("cat input.out");
            system("cat a.out");
            system("cat b.out");
            fgetc(stdin);
            fgetc(stdin);
        }
    }

}