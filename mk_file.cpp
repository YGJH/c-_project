#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main() {
    char name[100];
    cin >> name;
    char create_file[100];
    sprintf(create_file , "touch ../problems/%s.cpp" , name);
    system(create_file);
    char cp_command[100];
    sprintf(cp_command , "cp ../main.cpp ../problems/%s.cpp" , name);
    system(cp_command);

    return 0;
}

