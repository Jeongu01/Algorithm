#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int N, K, cnt, ans;
vector<int> v;
map<int, bool> visited;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}
	queue<vector<int>> q;
	q.push(v);
	for (int i = 1; i <= N; i++)
	{
		ans *= 10;
		ans += i;
	}
	int s = 0;
	for (int e : v)
	{
		s *= 10;
		s += e;
	}
	if (s == ans)
	{
		cout << 0;
		return 0;
	}

	while (!q.empty())
	{
		cnt++;
		int size = q.size();
		while (size--)
		{
			vector<int> cur = q.front();
			q.pop();
			for (int i = 0; i <= N - K; i++)
			{
				vector<int> nxt = cur;
				for (int j = 0; j < K / 2; j++)
				{
					int temp = nxt[i + j];
					nxt[i + j] = nxt[i + K - 1 - j];
					nxt[i + K - 1 - j] = temp;
				}
				int t = 0;
				for (int e : nxt)
				{
					t *= 10;
					t += e;
				}
				if (t == ans)
				{
					cout << cnt;
					return 0;
				}
				if (visited[t] == false)
				{
					visited[t] = true;
					q.push(nxt);
				}
			}
		}
	}
	cout << -1;
}