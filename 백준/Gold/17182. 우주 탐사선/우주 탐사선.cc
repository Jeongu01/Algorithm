#include <iostream>
using namespace std;

int N, K, target, ans;
int arr[10][10];

void func(int mask, int src, int dist)
{
	if (mask == target)
	{
		ans = min(ans, dist);
		return;
	}
	int m = 0x0001;
	for (int i = 0; i < N; i++)
	{
		if ((mask & m) == 0)
		{
			func((mask | m), i, dist + arr[src][i]);
		}
		m = m << 1;
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	ans = 0x3f3f3f3f;
	int mask = 0x0001 << K;
	for (int i = 0; i < N; i++)
	{
		target = target | (0x0001 << i);
	}
	func(mask, K, 0);
	cout << ans;
}