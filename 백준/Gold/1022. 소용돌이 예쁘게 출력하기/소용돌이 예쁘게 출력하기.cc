#include <iostream>
using namespace std;

int r1, c1, r2, c2, r, c, cnt;
int dr[] = { 0, -1, 0, 1 };
int dc[] = { 1, 0, -1, 0 };
int arr[50][5];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> r1 >> c1 >> r2 >> c2;
	r2 -= r1; c2 -= c1;
	r -= r1; c -= c1;
	r1 = 0; c1 = 0;
	int full = (r2 + 1) * (c2 + 1), idx = 0, w = 2, num = 1, maxNum = 0;

	if (r1 <= r && r <= r2 && c1 <= c && c <= c2)
	{
		arr[r][c] = num;
		cnt++;
	}

	while (cnt < full)
	{
		int v = w / 2;
		for (int i = 0; i < v && cnt <= full; i++)
		{
			r += dr[idx];
			c += dc[idx];
			num++;
			if (r1 <= r && r <= r2 && c1 <= c && c <= c2)
			{
				arr[r][c] = num;
				maxNum = max(maxNum, num);
				cnt++;
			}
		}
		w++;
		idx = (idx + 1) % 4;
	}

	int len = 0;
	while (maxNum > 0)
	{
		maxNum /= 10;
		len++;
	}
	for (int i = 0; i <= r2; i++)
	{
		for (int j = 0; j <= c2; j++)
		{
			int n = arr[i][j];
			int nLen = 0;
			while (n > 0)
			{
				n /= 10;
				nLen++;
			}
			for (int c = 0; c < len - nLen; c++)
			{
				cout << " ";
			}
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}