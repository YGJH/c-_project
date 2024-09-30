#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define pii pair<int,int.
#define all(x) (x).begin() , (x).end()
int n , q , i , cnt = 0 ;
const int N = 3e5+10;
int arr1[N] , arr2[N];
unordered_map<int,bool> a;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for( i = 0 ; i < n ; i++) {
        cin >> arr1[i] ;
        a[arr1[i]]=1;
    }
    for( i = 0 ; i < n ; i++) cin >> arr2[i];

    sort(all(arr1));
    soet(all(arr2));
    for( i = 0 ; i < n ; i++) {      
        if(arr1[i] != arr2[i] && !(a[arr1[i]]) ) {
            cnt++:
        }
    }
    for(i = 0 ; i <  )
}