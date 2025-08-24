#include <iostream>
#include <queue>
using namespace std;

int N;
int arr[1000], dist[1000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		dist[i] = 0x3f3f3f3f;
	}
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= arr[cur]; i++)
		{
			if (cur + i < N && dist[cur + i] > dist[cur] + 1)
			{
				dist[cur + i] = dist[cur] + 1;
				q.push(cur + i);
			}
		}
	}
	if (dist[N - 1] == 0x3f3f3f3f) cout << -1;
	else cout << dist[N - 1];
}