#include <iostream>
using namespace std;

int N;
int arr[21];
int dp[21];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	dp[1] = 1;
	arr[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		arr[i] = dp[i - 1];
		dp[i] = dp[i - 1] * 2;
		if (i - 3 >= 1 && (i - 3) % 2 != 0)
			dp[i] -= arr[i - 3];
		if (i - 4 >= 1 && (i - 4) % 2 == 0)
			dp[i] -= arr[i - 4];
	}
	cout << dp[N];
}