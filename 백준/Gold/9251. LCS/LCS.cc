#include <iostream>
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
	cout << arr[alen][blen];
}