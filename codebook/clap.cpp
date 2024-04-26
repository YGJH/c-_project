#include <bits/stdc++.h>
using namespace std;
int main() {
    while(1) {
        system("cd /home/charles/Documents/c-_project/exe_file");
        system("./gen_testcases > input.out");
        system("./wa < input.out > ac.out");
        system("./ac < input.out > wa.out");
        FILE * ac = fopen("ac.out" , "r");
        FILE * wa = fopen("wa.out" , "r");
        char tmp[3000], tmp2[3000] ;
        fseek(ac , 0 , SEEK_END);
        int len1 = ftell(ac);
        fseek(wa , 0 , SEEK_END);
        int len2 = ftell(wa);
        rewind(ac);
        rewind(wa);
        fread(tmp , 1 , len1 , ac);
        fread(tmp2 , 1 , len2 , wa);
        // cout << len1 << ' ' << len2 << endl;
        int now = 0;
        bool ok = true;
        while(now < len1) {
            if(tmp[now] != tmp2[now]) {
                cerr << tmp[now] << ' ' << tmp2[now] << endl;
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
            printf("ac output: \n");
            system("cat ac.out");
            printf("wa output:\n");
            system("cat wa.out");
            fgetc(stdin);
            fgetc(stdin);
        }
    }

}