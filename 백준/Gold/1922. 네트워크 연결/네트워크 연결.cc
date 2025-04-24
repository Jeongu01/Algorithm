#include <iostream>
#include <queue>
using namespace std;

int N, M;
int parent[1001];

struct Edge
{
	int a, b, w;
	Edge(int A, int B, int W) : a(A), b(B), w(W) { }

	bool operator<(const Edge& e) const
	{
		return this->w > e.w;
	}
};

int f(int a)
{
	if (parent[a] == a) return a;
	return parent[a] = f(parent[a]);
}

void u(int a, int b)
{
	a = f(a);
	b = f(b);
	if (a != b)
		parent[b] = a;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<Edge> pq;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		pq.push(Edge(a, b, c));
	}

	int cnt = 0, answer = 0;
	while (cnt < N && !pq.empty())
	{
		Edge e = pq.top();
		pq.pop();

		if (f(e.a) != f(e.b))
		{
			cnt++;
			answer += e.w;
			u(e.a, e.b);
		}
	}

	cout << answer;

	return 0;
}