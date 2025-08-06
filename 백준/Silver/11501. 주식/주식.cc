#include <iostream>
using namespace std;

int arr[1'000'001];
int m[1'000'001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}

		int value = 0;
		for (int i = N - 1; i >= 0; i--)
		{
			value = max(value, arr[i]);
			m[i] = value;
		}

		long long ans = 0;
		for (int i = 0; i < N; i++)
		{
			int a = m[i] - arr[i];
			if (a > 0)
			{
				ans += a;
			}
		}
		cout << ans << "\n";
	}
}