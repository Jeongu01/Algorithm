#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<int> link[2001];
bool destroyed[2001];
bool target[2001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int U, V;
		cin >> U >> V;
		link[U].push_back(V);
		link[V].push_back(U);
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int c;
		cin >> c;
		destroyed[c] = true;
		target[c] = true;
	}

	vector<int> ans;
	for (int i = 1; i <= N; i++)
	{
		if (target[i])
		{
			bool bomb = true;
			for (int r : link[i])
			{
				if (!target[r])
				{
					bomb = false;
					break;
				}
			}
			if (bomb)
			{
				ans.push_back(i);
				destroyed[i] = false;
				for (int r : link[i])
				{
					destroyed[r] = false;
				}
			}
		}
	}

	bool exist = true;
	for (int i = 1; i <= N; i++)
	{
		if (destroyed[i])
		{
			exist = false;
			break;
		}
	}
	if (exist)
	{
		cout << ans.size() << "\n";
		for (int a : ans)
		{
			cout << a << " ";
		}
	}
	else
	{
		cout << "-1";
	}
}