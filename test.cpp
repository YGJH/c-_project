#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
int N,M,s[2050],e[2050];
vector<int> cook_time;
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for (int i=0;i<N;i++) cin>>s[i];
    for (int i=0;i<M;i++) cin>>e[i];
    for (int i=0;i<N;i++) for (int j=0;j<M;j++) if (e[j]>=s[i]) cook_time.push_back(e[j]-s[i]);
    sort(cook_time.begin(),cook_time.end());
    if (!cook_time.size()){
        cout<<"0\n";
        return 0;
    }
    int ans=cook_time[0],cnt=1,temp=1;
    for (int i=1;i<cook_time.size();i++){
        if (cook_time[i]==cook_time[i-1]) temp++;
        else{
            if (temp>cnt) ans=cook_time[i-1],cnt=temp,temp=1;
            else temp=1;
        }
    }
    if (temp>cnt) ans=cook_time[cook_time.size()-1],cnt=temp,temp=1;
    cout<<ans<<endl;
    return 0;
}
