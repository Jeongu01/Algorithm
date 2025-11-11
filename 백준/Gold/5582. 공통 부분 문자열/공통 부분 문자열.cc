#include <iostream>
using namespace std;

int arr[4001][4001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string A, B;
	cin >> A >> B;
	int alen = A.length(), blen = B.length(), ans = 0;
	for (int i = 0; i < alen; i++)
	{
		for (int j = 0; j < blen; j++)
		{
			if (A.at(i) == B.at(j)) arr[i + 1][j + 1] = arr[i][j] + 1;
			else arr[i + 1][j + 1] = 0;
			ans = max(ans, arr[i + 1][j + 1]);
		}
	}
	cout << ans;
}