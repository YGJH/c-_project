#include <bits/stdc++.h>
using namespace std;
int main() {
    while(1) {
        system("./gen_testcases > input.out");
        system("./ac < input.out > a.out");
        system("./dp2_c < input.out > b.out");
        system("cat input.out");
        system("cat a.out");
        system("cat b.out");
        fgetc(stdin);
    }

}