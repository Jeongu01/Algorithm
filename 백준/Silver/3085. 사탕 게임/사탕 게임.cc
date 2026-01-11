#include <iostream>
using namespace std;

int N, ans;
char arr[50][50];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void swap(int r1, int c1, int r2, int c2)
{
	char temp = arr[r1][c1];
	arr[r1][c1] = arr[r2][c2];
	arr[r2][c2] = temp;
}

void cntRow(int r)
{
	int cnt = 1;
	char std = arr[r][0];
	for (int k = 1; k < N; k++)
	{
		if (arr[r][k] == std) cnt++;
		else
		{
			ans = max(ans, cnt);
			cnt = 1;
			std = arr[r][k];
		}
	}
	ans = max(ans, cnt);
}

void cntCol(int c)
{
	int cnt = 1;
	char std = arr[0][c];
	for (int k = 1; k < N; k++)
	{
		if (arr[k][c] == std) cnt++;
		else
		{
			ans = max(ans, cnt);
			cnt = 1;
			std = arr[k][c];
		}
	}
	ans = max(ans, cnt);
}

void func(int r, int c)
{
	for (int i = 0; i < 4; i++)
	{
		int nR = r + dr[i];
		int nC = c + dc[i];
		if (nR >= 0 && nR < N && nC >= 0 && nC < N
			&& arr[r][c] != arr[nR][nC])
		{
			swap(r, c, nR, nC);
			cntRow(r);
			cntCol(c);
			swap(r, c, nR, nC);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = s.at(j);
		}
	}

	for (int i = 0; i < N; i++)
	{
		cntRow(i);
		cntCol(i);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			func(i, j);
		}
	}

	cout << ans;
}