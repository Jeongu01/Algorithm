#include <iostream>
#include <queue>
using namespace std;

int pos[100'001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i <= 100'000; i++) pos[i] = 0x3f3f3f3f;

	int N, K;
	cin >> N >> K;
	queue<int> q;
	q.push(K);
	int t = -1;
	while (!q.empty())
	{
		int size = q.size();
		t++;
		while (size--)
		{
			int cur = q.front();
			q.pop();
			while (pos[cur] > t)
			{
				pos[cur] = t;
				if (cur - 1 >= 0 && pos[cur - 1] > t + 1) q.push(cur - 1);
				if (cur + 1 <= 100'000 && pos[cur + 1] > t + 1) q.push(cur + 1);
				if (cur % 2 == 0) cur /= 2;
				else break;
			}
		}
	}
	cout << pos[N];
}