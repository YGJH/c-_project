#include <stdio.h>
#include <stdlib.h>
 struct  node {
    int u , v , w;
    node(){};
    node(int uu, int vv ,int ww) {
        u = uu;
        v = vv;
        w = ww;
    }
};
signed main() {
    int s;
    scanf("%d", &s);
    int u, v, w;
    const int INF = 1e9;
    int mx = 0 , sz=0;
    node E[100];
    int dis[100];
    while(scanf("%d %d %d" , &u , &v , &w) != EOF) {
        mx = mx > u ? mx : u;
        mx = mx > v ? mx : v;
        E[sz++] = {u , v , w};
        dis[u] = INF;
        dis[v] = INF;
    }
    dis[s] = 0;
    for(int i = 0 ; i <= mx - 1 ; i++) {
        for(int i = 0 ; i < sz ; i++) {
            if(dis[E[i].u] + E[i].w < dis[E[i].v]) {
                dis[E[i].v] = dis[E[i].u] + E[i].w;
            }
        }
    }
    for(int i = 1 ; i < mx ; i++) {
        for(int j = 0 ; j < sz ; j++) {
            if(dis[E[j].u] + E[j].w < dis[E[j].v]) {
                dis[E[j].v] = -INF;
                break;
            }
        }
    }
    for(int i = 0 ; i <= mx ; i++) {
        if(dis[i] == INF) 
            printf("%d INF\n" , i); 
        else
        printf("%d %d\n", i, dis[i]);
    }
}