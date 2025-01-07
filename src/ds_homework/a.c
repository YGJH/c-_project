#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define min(a, b) ((a) > (b) ? (b) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))

int ans[1001];
int E[1001][1001];

typedef struct {
	int val;
	int idx;
} node;
typedef struct {
	node arr[1001];
	int size;
} Heap;

void insert(node val, Heap **heap) {
	(*heap)->arr[++((*heap)->size)] = val;
	int i = (*heap)->size;
	while (i > 1 && (*heap)->arr[i].val < (*heap)->arr[i / 2].val) {
		node tmp = (*heap)->arr[i];
		(*heap)->arr[i] = (*heap)->arr[i / 2];
		(*heap)->arr[i / 2] = tmp;
		i /= 2;
	}
}

node top(Heap **heap) { return (*heap)->arr[1]; }
bool empty(Heap **heap) { return (*heap)->size == 0; }

void heapify(Heap **heap, int i) {
	i = 1;
	while (i <= (*heap)->size) {
		int l = i * 2;
		int r = i * 2 + 1;
		int min = i;
		if (l <= (*heap)->size && (*heap)->arr[l].val < (*heap)->arr[min].val) {
			min = l;
		}
		if (r <= (*heap)->size && (*heap)->arr[r].val < (*heap)->arr[min].val) {
			min = r;
		}
		if (min == i)
			break;
		node tmp = (*heap)->arr[i];
		(*heap)->arr[i] = (*heap)->arr[min];
		(*heap)->arr[min] = tmp;
		i = min;
	}
}
int dis[1001];
node tmp;
void dijkstra(int s, int mx, Heap **heap) {

	for(int i = 0 ; i <= mx ; i++) dis[i] = 1e9;
	dis[s] = 0;
	node tmp; tmp.idx = s , tmp.val = 0;
	insert(tmp , heap);
	bool vis[1001] = {0};
	while (!empty(heap)) {
		// for(int i = 1 ; i <= (*heap)->size ; i++){
		// 	printf("%d %d\n" , (*heap)->arr[i].idx , (*heap)->arr[i].val);
		// }
		// putchar('\n');
		node u = top(heap);
		(*heap)->arr[1] = (*heap)->arr[(*heap)->size--];
		heapify(heap, 1);
		if (vis[u.idx])
			continue;
		vis[u.idx] = 1;
		dis[u.idx] = min(dis[u.idx] , u.val);
		for (int i = 0; i <= mx; i++) {
			if (i == u.idx || E[u.idx][i] == 0 || i == u.idx || vis[i])
				continue;
			tmp.val = E[u.idx][i] + dis[u.idx];
			tmp.idx = i;
			insert(tmp, heap);
		}
	}
}

signed main() {
	int s;
	scanf("%d", &s);
	int u, v, w;
	int mx = 0;
	while (scanf("%d %d %d", &u, &v, &w) != EOF) {
		E[u][v] = w;
		E[v][u] = w;
		mx = max(mx, max(u, v));
	}
	Heap *heap = (Heap *)malloc(sizeof(Heap));
	heap->size = 0;
	dijkstra(s, mx, &heap);
	free(heap);
	for (int i = 0; i <= mx; i++) {
		printf("%d: %d\n", i, dis[i]);
	}

	return 0;
}