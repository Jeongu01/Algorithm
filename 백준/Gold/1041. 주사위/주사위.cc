#include <iostream>
using namespace std;

long long N;
int arr[6];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int m = 0x3f3f3f3f;
	for (int i = 0; i < 6; i++)
	{
		cin >> arr[i];
		m = min(m, arr[i]);
	}
	long long ans = 0;
	if (N == 1)
	{
		m = 0;
		int ans = 0;
		for (int i = 0; i < 6; i++)
		{
			ans += arr[i];
			m = max(m, arr[i]);
		}
		ans -= m;
		cout << ans;
		return 0;
	}

	ans += (N - 2) * (N - 2) * m
		+ (N - 2) * (N - 1) * 4 * m;
	
	int m2 = 0x3f3f3f3f;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i == j)
				continue;
			if (i + j == 5)
				continue;
			m2 = min(m2, arr[i] + arr[j]);
		}
	}
	ans += (N * 2 - 3) * 4 * m2;

	int m3 = 0x3f3f3f3f;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				if (i == j || j == k || k == i)
					continue;
				if (i + j == 5 || j + k == 5 || k + i == 5)
					continue;
				m3 = min(m3, arr[i] + arr[j] + arr[k]);
			}
		}
	}
	ans += 4 * m3;
	cout << ans;
}