#include <iostream>
using namespace std;

int r[10][10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bool OnOff[10][7] = {
		{ 1, 1, 1, 0, 1, 1, 1 },	// 0
		{ 0, 0, 1, 0, 0, 1, 0 },	// 1
		{ 1, 0, 1, 1, 1, 0, 1 },	// 2
		{ 1, 0, 1, 1, 0, 1, 1 },	// 3
		{ 0, 1, 1, 1, 0, 1, 0 },	// 4
		{ 1, 1, 0, 1, 0, 1, 1 },	// 5
		{ 1, 1, 0, 1, 1, 1, 1 },	// 6
		{ 1, 0, 1, 0, 0, 1, 0 },	// 7
		{ 1, 1, 1, 1, 1, 1, 1 },	// 8
		{ 1, 1, 1, 1, 0, 1, 1 }		// 9
	};

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 7; k++)
			{
				r[i][j] += OnOff[i][k] ^ OnOff[j][k];
			}
		}
	}

	int N, K, P, X;	// N : 최대 층, K : 자릿수, P : 최대 반전 수, X : 현재 층
	cin >> N >> K >> P >> X;

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i == X) continue;
		int temp = X;
		int tempi = i;
		int p = 0;
		for (int k = 0; k < K; k++)
		{
			int tempAt = temp % 10;
			int iAt = tempi % 10;
			temp /= 10;
			tempi /= 10;
			p += r[tempAt][iAt];
		}
		if (p <= P) answer++;
	}

	cout << answer;

	return 0;
}