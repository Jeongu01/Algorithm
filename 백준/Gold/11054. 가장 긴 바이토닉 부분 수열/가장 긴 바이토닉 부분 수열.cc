#include <iostream>
using namespace std;

int arr[1000];
int up[1000];
int down[1000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		up[i] = 1;
		down[i] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				up[i] = max(up[i], up[j] + 1);
			}
		}
	}
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (arr[j] < arr[i])
			{
				down[i] = max(down[i], down[j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans = max(ans, up[i] + down[i]);
	}
	cout << ans - 1;
}