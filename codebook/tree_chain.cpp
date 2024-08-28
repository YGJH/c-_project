#include <iostream>
using namespace std;

const int MXN = 2e4;
int par[MXN], dep[MXN], sz[MXN], son[MXN];
/*第一次 DFS 求：「父節點(par)」、「深度(dep)」、「子樹大小(sz)」、「重兒子(son)」*/
/*一開始要先 memset(son,0,sizeof(son)); 並讓 sz[0]=0*/

void dfs1(int now, int fa, int now_deep){//當前節點, 爸爸, 目前深度
    dep[now] = now_deep;
    par[now] = fa;
    sz[now]  = 1;
    for(auto nxt : v[now]){
        if(nxt == fa)continue;
        dfs1(nxt, now, now_deep + 1);
        sz[now] += sz[nxt];
        if(sz[nxt] > sz[son[now]]) son[now] = nxt;
    }
}

/*第二次 DFS 求：「走訪編號(dfn)」、「目前點所在的鏈的頂端點(top)」
dfn 為走訪編號，此編號為線段樹上的位置*/

int top[MXN], dfn[MXN], rnk[MXN];
int cnt = 0;
void dfs2(int now, int fa, int now_top){//現在的點, 爸爸, 目前的頂端點
    top[now] = now_top;
    rnk[now] = cnt;
    dfn[now] = cnt++;
    if(son[now] != 0) dfs2(son[now], now, now_top);//為了讓編號連續，先往重兒子走
    for(auto nxt : v[now]){
        if(nxt == fa || nxt == son[now])continue;
        dfs2(nxt, now, nxt);//往其他輕兒子走
    }
}

int32_t main() {
    return 0;
}