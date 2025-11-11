#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string A, B;
	cin >> A >> B;
	int alen = A.length(), blen = B.length();
	for (int i = 0; i < alen; i++)
	{
		for (int j = 0; j < blen; j++)
		{
			if (A.at(i) == B.at(j)) arr[i + 1][j + 1] = arr[i][j] + 1;
			else arr[i + 1][j + 1] = max(arr[i][j + 1], arr[i + 1][j]);
		}
	}
	cout << arr[alen][blen] << "\n";
	string ans;
	while (true)
	{
		if (arr[alen][blen] == 0) break;
		else if (arr[alen - 1][blen] == arr[alen][blen]) alen--;
		else if (arr[alen][blen - 1] == arr[alen][blen]) blen--;
		else
		{
			ans += A.at(alen - 1);
			alen--;
			blen--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}