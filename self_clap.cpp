#include <bits/stdc++.h>
using namespace std;
int main() {
    char file_name[100];
    char tmp[400];
    fgets(file_name , sizeof(file_name) , stdin);
    strtok(file_name , "\r\n");
    sprintf(tmp , "echo | ./exe_file/%s < input.out" , file_name);
    while(1) {
        system("./gen_testcases > input.out");
        system("echo \"input : \"");
        system("cat input.out");
        // printf("%s" , tmp);
        system("\n");
        system("echo \"output : \"");
        system(tmp);
        fgetc(stdin);
    }
}