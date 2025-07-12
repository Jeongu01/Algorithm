#include <iostream>
using namespace std;

int N, M;
bool arr[1001][1001];
int ans[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int input;
			cin >> input;
			if (input == 1) arr[i][j] = true;
		}
	}
	for (int i = 0; i < M; i++)
	{
		if (arr[0][i]) ans[0][i] = 1;
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j])
			{
				int cnt = ans[i][j];
				if (j - 1 >= 0 && arr[i + 1][j - 1])
				{
					ans[i + 1][j - 1] += cnt;
					ans[i + 1][j - 1] %= 1'000'000'007;
				}
				if (arr[i + 1][j])
				{
					ans[i + 1][j] += cnt;
					ans[i + 1][j] %= 1'000'000'007;
				}
				if (j + 1 < M && arr[i + 1][j + 1])
				{
					ans[i + 1][j + 1] += cnt;
					ans[i + 1][j + 1] %= 1'000'000'007;
				}
			}
		}
	}
	long long sum = 0;
	for (int i = 0; i < M; i++)
	{
		sum += ans[N - 1][i];
		sum %= 1'000'000'007;
	}
	cout << sum;
}