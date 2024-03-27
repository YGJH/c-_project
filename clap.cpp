#include <bits/stdc++.h>
using namespace std;
int main() {
    char name[300] ;
    fgets(name , sizeof(name) , stdin);
    strtok(name , "\n\r");
    char com[400];
    sprintf(com , "./%s < input.out > b.out" , name);
    while(1) {

        system("./gen_testcases > input.out");
        system("./ac < input.out > a.out");
        system(com);
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
            printf("input:\n");
            system("cat input.out");
            printf("\nac output: \n");
            system("cat a.out");
            printf("\n wa output:\n");
            system("cat b.out");
            fgetc(stdin);
            fgetc(stdin);
        }
    }

}