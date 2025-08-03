#include <iostream>
using namespace std;

int arr[2][100'001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int i = 1; i < n; i++)
		{
			arr[0][i] += max(arr[1][i - 1], arr[1][i - 2]);
			arr[1][i] += max(arr[0][i - 1], arr[0][i - 2]);
		}
		cout << max(arr[0][n - 1], arr[1][n - 1]) << "\n";
	}
}