#include <iostream>
using namespace std;

int N;
int arr[999][999];
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int r = N / 2, c = N / 2;
	int idx = 0, in = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			arr[r][c] = in;
			in++;
			r += dr[idx];
			c += dc[idx];
		}
		if (r < 0 || c < 0 || N <= r || N <= c)
			break;
		idx++;
		for (int j = 0; j < i; j++)
		{
			arr[r][c] = in;
			in++;
			r += dr[idx];
			c += dc[idx];
		}
		if (r < 0 || c < 0 || N <= r || N <= c)
			break;
		idx++;
		idx %= 4;
	}
	int trg;
	cin >> trg;
	int ansR, ansC;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j] << " ";
			if (arr[i][j] == trg)
			{
				ansR = i;
				ansC = j;
			}
		}
		cout << "\n";
	}
	cout << ansR + 1 << " " << ansC + 1;
}