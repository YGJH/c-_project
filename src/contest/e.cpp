#include <Bits/stdc++.h>
using namespace std;
int arr[20000];
int32_t main() {

    int n;
    cin >> n;
    int init = 0;
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    int tim = 0;
    int nn = n;
    while(init < n && tim < nn) {
        if(arr[init] != arr[n-1]){
            break;
        }
        arr[n++] = arr[init];
        init++;
        tim++;
    }
 
    vector<bool> vis(101, 0);
    int now = init;
    bool w = 0;
    vector<int> as;
    for(; init < n ; init++) {
        if(w) {
            if(vis[arr[init]]!=0) {
                as.push_back(arr[init]);
            }
            if(arr[init] != arr[init-1]) {
                vis[arr[init-1]]=1;
            }
        }
        w=1;
    }
    // cout << as.size() << endl;
    if(as.size()){
        sort(as.begin() , as.end());
        as.erase(unique(as.begin() , as.end()) , as.end());
        cout << "No" << endl;
        for(auto &a : as) {
            cout << a << ' ';   
        }
    }else {
        cout << "Yes" << endl;

    }


    return 0;
}