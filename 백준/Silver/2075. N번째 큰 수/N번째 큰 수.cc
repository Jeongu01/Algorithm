#include <iostream>
#include <queue>
using namespace std;

int N;
int arr[1500][1500];
int idx[1500];
priority_queue<pair<int, int>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		pq.push({ -arr[idx[i]][i], i });
	}
	for (int i = 0; i < N * N - N; i++)
	{
		auto cur = pq.top();
		pq.pop();
		int iidx = cur.second;
		idx[iidx]++;
		if (idx[iidx] >= N)
			continue;
		pq.push({ -arr[idx[iidx]][iidx], iidx });
	}
	cout << -pq.top().first;
}