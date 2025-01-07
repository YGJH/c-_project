#include <bits/stdc++.h>
#define MAXN 5050
#define INF 0x3f3f3f3f
#define P pair<int,int>

using namespace std;

struct edge
{
	int to, cap, cost, rev;
};

int n, m, s, t;
int u, v, c, w;
int maxFlow, minCost;

vector<edge> G[MAXN];
int h[MAXN];
int dist[MAXN], prevv[MAXN], preve[MAXN];

void addedge(int from, int to, int cap, int cost)
{
	edge temp1 = { to, cap, cost, (int)G[to].size() };
	edge temp2 = { from, 0, -cost, (int)G[from].size() - 1 };
	G[from].push_back(temp1);
	G[to].push_back(temp2);
}

//Dijkstra算法实现
void MCMF(int s, int t, int f)
{
	fill(h + 1, h + 1 + n, 0);
	while (f > 0)
	{
		priority_queue<P, vector<P>, greater<P> > D;
		memset(dist, INF, sizeof dist);
		dist[s] = 0; D.push(P(0, s));
		while (!D.empty())
		{
			P now = D.top(); D.pop();
			if (dist[now.second] < now.first) continue;
			int v = now.second;
			for (int i = 0; i<(int)G[v].size(); ++i)
			{
				edge &e = G[v][i];
				if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])
				{
					dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
					prevv[e.to] = v;
					preve[e.to] = i;
					D.push(P(dist[e.to], e.to));
				}
			}
		}
		if (dist[t] == INF) break;
		for (int i = 1; i <= n; ++i) h[i] += dist[i];
		int d = f;
		for (int v = t; v != s; v = prevv[v])
			d = min(d, G[prevv[v]][preve[v]].cap);
		f -= d; maxFlow += d;
		minCost += d * h[t];
		for (int v = t; v != s; v = prevv[v])
		{
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{

	cout << "节点数为："; cin >> n;
	cout << "边数为："; cin >> m;
	cout << "源点编号为："; cin >> s;
	cout << "汇点编号为："; cin >> t;

	cout << "输入 " << m << " 条边的信息：" << endl;
	while (m--)
	{
		cout << "起点："; cin >> u;
		cout << "终点："; cin >> v;
		cout << "容量："; cin >> c;
		cout << "费用："; cin >> w;
		cout << "-----------------" << endl;
		addedge(u, v, c, w);
	}

	MCMF(s, t, INF);

	cout << "最大流为：" << maxFlow << endl;
	cout << "最小费用为" << minCost << endl;
	cout << endl;

	system("pause");
	return 0;
}
