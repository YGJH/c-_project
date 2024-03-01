#include <bits/stdc++.h>
using namespace std;
int main() {
    while(1) {
        system("./gen_testcases.cpp > input.out");
        system("./problems/ac.cpp < input.out > a.out");
        system("./problems/wa.cpp < input.out > b.out");
        system("cat a.out");
        system("cat a.out");
        system("cat b.out");
        fgetc(stdin);
    }

}