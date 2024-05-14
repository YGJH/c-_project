#include <bits/stdc++.h>
using namespace std;
        char aa[100];
        char bb[100];
signed main() {
    system("cd /home/charles/Documents/cpp/c-_project/exe_file");
    char magic[]= "./gen_testcases > input.out";
    char magic2[] = "./small2large < input.out > output.out";
    char magic3[] = "./ac < input.out > ac.out";
    int i;
    bool fin = true;
    while(fin) {
        system(magic);
        system(magic2);
        system(magic3);
        FILE * ac = fopen("/home/charles/Documents/cpp/c-_project/exe_file/ac.out" , "r+");
        FILE * wa = fopen("/home/charles/Documents/cpp/c-_project/exe_file/output.out" , "r+");
        fseek(ac , 0 , SEEK_END);
        int sz = ftell(ac);
        rewind(ac);
        fread(bb , sz , 1 , wa);
        fread(aa , sz , 1 , ac);
        for( i = 0 ; i <= sz ; i++) {
            if(aa[i] != bb[i]) {
                cout << -1 << endl;
                fin = false;
                fclose(ac);
                fclose(wa);
                return 0;
            }
        }
        cout << "correct" << endl; 
    }
}