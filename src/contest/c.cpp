#include <bits/stdc++.h>
using namespace std;
int n , m;
int count = 0;
bool bod[100][100];
void dfs(int x , int y) {
    // for(int i = 0 ; i < 3; i++) {
        if(x==n&&y==m) {
            ::count++;
            return;
        }
        else if(x>=n && y == m-1) {
            ::count++;
            return;
        }
        else if(x == 0 && y >= m) {
            ::count++;
            return ;
        }
        if(x >= n || y >= m) {
            return;
        }
        if(bod[x][y] == 1) {
            if(x+1<=n)
                dfs(x+1,y);
            else if(x+1>n && y + 1 <= m)
                dfs(0 , y+1);
        }
        if(bod[x][y] == 0) {
            bod[x][y] = 1;
            if(x+1<=n)
                dfs(x+1,y);
            else if(y + 1 <= m)
                dfs(0 , y+1);
            bod[x][y] = 0;
        }
        if(x + 1 < n && bod[x+1][y] == 0 && bod[x][y] == 0) {
            bod[x+1][y] = 1;
            bod[x][y] = 1;
            if(x+2<=n)
                dfs(x+2,y);
            else if(x+2>n && y + 1 <= m)
                dfs(0 , y+1);
            bod[x+1][y] = 0;
            bod[x][y] = 0;
        }
        if( y + 1 < m && bod[x][y+1] == 0 && bod[x][y] == 0) {
            bod[x][y+1] = 1;
            bod[x][y] = 1;
            if(x+1<=n)
                dfs(x+1,y);
            else if(x+1>n && y + 1 <= m)
                dfs(0 , y+1);
            bod[x][y+1] = 0;
            bod[x][y] = 0;

        }
    // }
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int n , m;
    cin >> n >> m;
    // ::n = 2 , ::m = 1;
    dfs(0 , 0);
    cout << ::count << endl;
}