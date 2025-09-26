#include <iostream>
using namespace std;

int N;
int arr[51][51];

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
			char c;
			cin >> c;
			arr[i][j] = c == 'Y' ? 1 : 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 1)
			{
				for (int k = 0; k < N; k++)
				{
					if (k == i) continue;
					if (arr[j][k] == 1 && arr[i][k] == 0)
					{
						arr[i][k] = 2;
						arr[k][i] = 2;
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] != 0) cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}