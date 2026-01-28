#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
int path[150'001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	fill(path, path + 150'000, -1);
	path[N] = 0;
	vector<int> ans;
	queue<int> q;
	q.push(N);
	int t = -1;
	while (!q.empty())
	{
		int size = q.size();
		t++;
		while (size--)
		{
			int cur = q.front(); q.pop();
			if (cur == K)
			{
				cout << t << "\n";
				int idx = K;
				while (idx != N)
				{
					ans.push_back(idx);
					idx = path[idx];
				}
				ans.push_back(N);
				reverse(ans.begin(), ans.end());
				for (int p : ans)
				{
					cout << p << " ";
				}
				return 0;
			}
			if (cur + 1 < 150'000 && path[cur + 1] == -1)
			{
				q.push(cur + 1);
				path[cur + 1] = cur;
			}
			if (cur - 1 >= 0 && path[cur - 1] == -1)
			{
				q.push(cur - 1);
				path[cur - 1] = cur;
			}
			if (cur + cur < 150'000 && path[cur + cur] == -1)
			{
				q.push(cur + cur);
				path[cur + cur] = cur;
			}
		}
	}
}