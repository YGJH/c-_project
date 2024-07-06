#include <bits/stdc++.h>
using namespace std;
int main() {
    char file_name[100];
    char tmp[400];
    fgets(file_name , sizeof(file_name) , stdin);
    strtok(file_name , "\r\n");
    sprintf(tmp , "echo | ./exe_file/%s < ./exe_file/input.out > ./exe_file/output.out && cat ./exe_file/output.out" , file_name);
    while(1) {
        system("./exe_file/gen_testcases > ./exe_file/input.out");
        system("echo \"input : \"");
        system("cat ./exe_file/input.out");
        system("\n");
        system("echo \"output : \"");
        system(tmp);
        fgetc(stdin);
    }
}