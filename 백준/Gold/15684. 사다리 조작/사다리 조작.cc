#include <iostream>
using namespace std;

int N, M, H;
int arr[31][11];

bool play()
{
	for (int i = 1; i <= N; i++)
	{
		int cur = i;
		for (int h = 1; h <= H; h++)
		{
			cur += arr[h][cur];
		}
		if (cur != i)
			return false;
	}
	return true;
}

bool add(int n)
{
	if (n == 0)
	{
		return play();
	}

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (arr[i][j] != 0 || arr[i][j + 1] != 0)
				continue;

			arr[i][j] = 1;
			arr[i][j + 1] = -1;
			if (add(n - 1) == true)
			{
				return true;
			}
			arr[i][j] = 0;
			arr[i][j + 1] = 0;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[a][b + 1] = -1;
	}
	int ans = -1;
	if (add(0)) ans = 0;
	else if (add(1)) ans = 1;
	else if (add(2)) ans = 2;
	else if (add(3)) ans = 3;

	cout << ans;
}