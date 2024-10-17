#include <bits/stdc++.h>
using namespace std;
int arr[(int)1e5+5]={};
bool cmp(int x,int y){
    return x>y;      //更改為降序排列
}
int32_t main(){
    for(int i=1;i<=100;i++) arr[i]=i;
    nth_element(arr+1,arr+50+1,arr+100+1);
    for(int i=1 ; i<= 100 ; i++) {
        cout << arr[i] << " \n"[i==100];
    }
}