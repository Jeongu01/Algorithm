#include <iostream>
#include <queue>
using namespace std;

int N, K;
bool visited[100'001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	queue<int> q;
	q.push(N);

	int cnt, t = -1;
	while (!q.empty())
	{
		int size = q.size();
		t++;
		cnt = 0;
		while (size--)
		{
			int cur = q.front();
			q.pop();
			visited[cur] = true;
			if (cur == K) cnt++;

			if (cur - 1 >= 0 && visited[cur - 1] == false) q.push(cur - 1);
			if (cur + 1 <= 100'000 && visited[cur + 1] == false) q.push(cur + 1);
			if (cur * 2 <= 100'000 && visited[cur * 2] == false) q.push(cur * 2);
		}
		if (cnt != 0) break;
	}
	cout << t << "\n" << cnt;
}