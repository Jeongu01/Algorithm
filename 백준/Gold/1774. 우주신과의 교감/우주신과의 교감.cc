#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int parent[1001];

struct Pos
{
	long x, y;
	Pos(long X, long Y) : x(X), y(Y) {}
};
vector<Pos> poses;

struct Edge
{
	double dist;
	int v1, v2;
	Edge(int V1, int V2) : v1(V1), v2(V2) 
	{
		dist = sqrt(pow(poses[v1].x - poses[v2].x, 2) + pow(poses[v1].y - poses[v2].y, 2));
	}
	bool operator<(const Edge& e) const
	{
		return this->dist > e.dist;
	}
};
priority_queue<Edge> edges;

int f(int a)
{
	if (a == parent[a]) return a;
	return a = f(parent[a]);
}

bool u(int a, int b)
{
	a = f(a);
	b = f(b);
	if (a != b)
	{
		parent[b] = a;
		return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	poses.push_back(Pos(0, 0));
	for (int i = 1; i <= N; i++)
	{
		int X, Y;
		cin >> X >> Y;
		poses.push_back(Pos(X, Y));
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j < i; j++)
			edges.push(Edge(i, j));

	for (int i = 0; i < M; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		u(v1, v2);
	}

	double ans = 0;
	int cnt = 0;
	while (!edges.empty() && cnt < N - 1)
	{
		Edge cur = edges.top();
		edges.pop();

		if (u(cur.v1, cur.v2))
		{
			ans += cur.dist;
			cnt++;
		}
	}

	printf("%.2f", ans);
}