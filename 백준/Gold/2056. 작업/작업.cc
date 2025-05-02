#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

struct Node
{
	int num, time;
	Node(int n, int t) : num(n), time(t) {};
	bool operator<(const Node& n) const
	{
		return this->time > n.time;
	}
};

int N;
int indegree[10001];
int times[10001];
vector<int> works[10001];
priority_queue<Node> pq;

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> times[i] >> indegree[i];
		if (indegree[i] == 0) pq.push(Node(i, times[i]));
		for (int j = 0; j < indegree[i]; j++)
		{
			int pre;
			cin >> pre;
			works[pre].push_back(i);
		}
	}

	int ans = 0;
	while (!pq.empty())
	{
		Node now = pq.top();
		pq.pop();
		ans = now.time;
		int size = works[now.num].size();
		for (int i = 0; i < size; i++)
		{
			int next = works[now.num][i];
			if (--indegree[next] == 0) pq.push(Node(next, now.time + times[next]));
		}
	}

	cout << ans;
}