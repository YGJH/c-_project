#include <iostream>
using namespace std;
#define int long long
int t,n,m,a,b,deg[1000050];
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>t;
    while (t--){
        int ans=0;
        cin>>n>>m;
        for (int i=0;i<m;i++){ 
            cin>>a>>b;
            if (a!=b) deg[b]++;
        }
        for (int i=0;i<n;i++) if (!deg[i]) ans++;
        cout<<ans<<endl;
        for (int i=0;i<1000050;i++) deg[i]=0;
    }
    return 0;
}