#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) > (b) ? (b) : (a)

signed main() {
	int s;
	scanf("%d", &s);
	int u, v, w;
	const int INF = 1e9;
	int mx = 0;
	int dis[100][100];
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			dis[i][j] = 1e9;
		}
	}
	while (scanf("%d %d %d", &u, &v, &w) != EOF) {
		mx = max(mx, max(u, v));
		dis[u][v] = min(w, dis[u][v]);
		dis[u][u] = 0;
		dis[v][v] = 0;
	}

	int con, tmp;
	for (int i = 0; i <= mx; i++) { // from
		// floyd warshall
		for (int j = 0; j <= mx; j++) { // to
			for (int k = 0; k <= mx; k++) {
				if (dis[j][i] == INF || dis[i][k] == INF)
					continue;
				if (dis[j][k] > dis[j][i] + dis[i][k]) {
					dis[j][k] = dis[j][i] + dis[i][k];
				}
			}
		}
	}

	for (int k = 0; k <= mx; k++) {
		for (int i = 0; i <= mx; i++) {
			for (int j = 0; j <= mx; j++) {
				if (dis[i][j] == INF || dis[j][k] == INF)
					continue;
				if (dis[i][j] + dis[j][k] < dis[i][k]) {
					// the distance is still updatable by a negative cylcle
					dis[i][k] = -INF;
                    break;
				}
			}
		}
	}

	for (int i = 0; i <= mx; i++) {
		for (int j = 0; j <= mx; j++) {
			if (dis[i][j] == -INF)
				printf("-INF  ");
			else if(dis[i][j] == INF) {
                printf("INF   ");
            }else{
				printf("%-5d ", dis[i][j]);

            }
		}
		printf("\n");
	}

	return 0;
}