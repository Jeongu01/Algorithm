#include <iostream>
using namespace std;

int AN, AM, BM, BK;
int A[101][101], B[101][101], ans[101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> AN >> AM;
	for (int i = 0; i < AN; i++)
	{
		for (int j = 0; j < AM; j++)
		{
			cin >> A[i][j];
		}
	}

	cin >> BM >> BK;
	for (int i = 0; i < BM; i++)
	{
		for (int j = 0; j < BK; j++)
		{
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < AN; i++)
	{
		for (int j = 0; j < BK; j++)
		{
			for (int k = 0; k < AM; k++)
			{
				ans[i][j] += A[i][k] * B[k][j];
			}
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}