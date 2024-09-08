#include <iostream>
#include <vector>
using namespace std;
int top[1000];
int getlca(int x,int y){
    while(top[x] != top[y]){
        if( dep[top[x]] < dep[top[y]] )//根據頂端點的深度往上跳
            y = par[top[y]];
        else 
            x = par[top[x]]; 
    }
    if(dep[x] > dep[y])return y;//這時候在同一條鏈了，回傳比較不深的點
    else return x;
}

// 求路徑上點權重和
int query(int x, int y){
    int lca = getlca(x, y);
    int ans = 0;
    
    //x -> lca 點權總和
    while( top[lca] != top[x] ){
        ans += seg.query( dfn[top[x]], dfn[x] );
        x = par[top[x]];
    }
    ans += seg.query( dfn[lca], dfn[x] );
    
    //y -> lca 點權總和
    while( top[lca] != top[y] ){
        ans += seg.query( dfn[top[y]], dfn[y] );
        y = par[top[y]];
    }
    ans += seg.query( dfn[lca], dfn[y] );
    
    ans -= seg.query( dfn[lca], dfn[lca] );//lca被重複算到一次，要扣掉
}


int32_t main() {
    return 0;
}