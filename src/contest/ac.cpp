#include <iostream>
using namespace std;
#define int unsigned long long
int x,y,ans=0;
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>x>>y;
    // if (0>=x && 0<=y) ans++;
    for (int i=1;i<64;i++){
        int tmp=0,cnt_len=i;
        for (int k=0;k<i;k++) tmp<<=1,tmp++;
        if (tmp>=x && tmp<=y && cnt_len<64) ans++;
        if (cnt_len>=64) break;
        for (int j=1;j<64;j++){
            int temp=tmp,cnt=0;
            for (int k=0;k<j;k++) temp*=2;
            cnt_len=i+j;
            if (cnt_len>=64) break;
            while (cnt_len<64){
                if (temp>=x && temp<=y && cnt_len<64) ans++;
                cnt++;
                if (cnt%2){
                    for (int k=0;k<i;k++) temp*=2,temp++;
                    cnt_len+=i;
                }
                else{
                    for (int k=0;k<j;k++) temp*=2;
                    cnt_len+=j;
                }
            }
        }
    }
    cout<<23<<endl;
    return 0;
}