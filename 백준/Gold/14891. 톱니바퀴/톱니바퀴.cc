#include <iostream>
using namespace std;

bool arr[4][8];

void turn(int n, bool dir, int dr)
{
	if (n == 1)
	{
		if (dr != -1 && arr[0][2] != arr[1][6]) turn(2, !dir, 1);
	}
	else if (n == 2)
	{
		if (dr != -1 && arr[1][2] != arr[2][6]) turn(3, !dir, 1);
		if (dr != 1 && arr[1][6] != arr[0][2]) turn(1, !dir, -1);
	}
	else if (n == 3)
	{
		if (dr != -1 && arr[2][2] != arr[3][6]) turn(4, !dir, 1);
		if (dr != 1 && arr[2][6] != arr[1][2]) turn(2, !dir, -1);
	}
	else if (n == 4)
	{
		if (dr != 1 && arr[3][6] != arr[2][2]) turn(3, !dir, -1);
	}

	if (!dir)
	{
		bool temp = arr[n - 1][0];
		for (int i = 0; i < 7; i++)
		{
			arr[n - 1][i] = arr[n - 1][i + 1];
		}
		arr[n - 1][7] = temp;
	}
	else
	{
		bool temp = arr[n - 1][7];
		for (int i = 7; i > 0; i--)
		{
			arr[n - 1][i] = arr[n - 1][i - 1];
		}
		arr[n - 1][0] = temp;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	for (int i = 0; i < 4; i++)
	{
		cin >> s;
		for (int j = 0; j < 8; j++)
		{
			arr[i][j] = s.at(j) != '0';
		}
	}
	int K;
	cin >> K;
	while (K--)
	{
		int n, dir;
		cin >> n >> dir;
		turn(n, dir == 1, 0);
	}
	int ans = 0;
	if (arr[0][0] == 1) ans += 1;
	if (arr[1][0] == 1) ans += 2;
	if (arr[2][0] == 1) ans += 4;
	if (arr[3][0] == 1) ans += 8;
	cout << ans;
}