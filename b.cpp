#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ishowspeed ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
inline void wr(int x) {
    if(x<0)
        putchar('-'),x=-x;
    char st[300];
    int now = 0;
    while(x) {
        st[now++] = x % 10 + 48;
        x/=10;        
    }
    while(now) {
        putchar(st[--now]);
    }
}
inline void re(int &x) {
    char c = getchar();
    x = 0 ;
    bool w = false;
    while(c < 48 && c > 57) {
        w |= (c == '-') ;
        c = getchar();
    }
    while(c >= 48 && c <= 57) {
        x = (x<< 1) + (x<<3) + (c & 15);
        c = getchar();
    }
    if(w) 
        x = -x;
}
const int N = 2000;
int arr[2000][2000] , arr2[2000][2000];
vector<vector<int>> up(N, vector<int> (N));
vector<vector<int>> down(N, vector<int> (N));
vector<vector<int>> rig(N, vector<int> (N));
vector<vector<int>> lef(N, vector<int> (N));

signed main() {
    int n , m;
    cin >> n >> m;
    cerr << n << m << endl;
    for(int j = 0 ; j < n ; j++) {
        for(int k = 0 ; k < m ; k++) {
            cin >> arr[j][k];
            up[j][k] = j;
            down[j][k] = j;
            rig[j][k] = k;
            lef[j][k] = k;
        }
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            while(up[i][j] > 0 && up[i][j] < n -1 && arr[up[i][j]-1][j] == arr2[up[i][j]-1][j]) up[i][j] = up[up[i][j] - 1][j];
            // if (arr[i][j]==arr2[i][j]) up[i][j]=up[i-1][j]+1;
        }
    }
    cerr << "fin" << endl;
    
    for(int i = n - 1 ; i >= 0 ; i--) {
        for(int j = 0 ; j < m ; j++) {
            while(down[i][j] < n - 1 && down[i][j] > 0 && arr[down[i][j]+1][j] == arr2[down[i][j]+1][j]) down[i][j] = down[down[i][j] + 1][j];
            // if (arr[i][j]==arr2[i][j]) down[i][j]=down[i+1][j]+1;
        }
    }
    cerr << "fin" << endl;

    for(int i = 0 ; i < n ; i++) {
        for(int j = m ; j >= 0 ; j--) {
            while(rig[i][j] < n - 1 && rig[i][j] > 0 && arr[i][rig[i][j]+1] == arr2[i][rig[i][j]+1]) rig[i][j] = rig[i][rig[i][j]+ 1];
        }
    }
    cerr << "fin" << endl;

    for(int i = 0 ; i < n ; i ++) {
        for(int j = 0 ; j < m ; j++) {
            while(lef[i][j] > 0 && lef[i][j] < n - 1 && arr[i][lef[i][j]-1] == arr2[i][lef[i][j]-1]) lef[i][j] = lef[i][lef[i][j]- 1];
            // if (arr[i][j]==arr2[i][j]) lef[i][j]=lef[i][j-1]+1;
        }
    }
    cerr << "fin" << endl;
    
    int ans = 0;
    for(int i = 0 ; i < n ; i ++) {
        for(int j = 0 ; j < m ; j++) {
            cerr << "up: " << up[i][j] << " down: " << down[i][j] << " rig: " << rig[i][j] << " lef: " << lef[i][j] << ' ';
            ans = max(ans , abs(lef[i][j] - rig[i][j]) * abs(up[i][j] - down[i][j]) );
        }
    cerr << endl;
    }

    cout << ans << endl;
    return 0;
}