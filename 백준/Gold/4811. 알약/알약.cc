#include <iostream>
using namespace std;

long long arr[31][31];
long long ans[31];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	arr[1][1] = 1;
	ans[1] = 1;
	for (int i = 2; i <= 30; i++)
	{
		arr[i][1] = ans[i - 1];
		ans[i] += arr[i][1];
		for (int j = 2; j <= i; j++)
		{
			arr[i][j] = arr[i][j - 1];
			arr[i][j] -= arr[i - 1][j - 2];
			ans[i] += arr[i][j];
		}
	}

	while (true)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		cout << ans[n] << "\n";
	}
}