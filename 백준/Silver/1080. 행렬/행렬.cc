#include<iostream>
using namespace std;

int N, M, ans;
bool A[50][50];
bool B[50][50];

void func(int r, int c)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			A[r + i][c + j] = !A[r + i][c + j];
		}
	}
	ans++;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			A[i][j] = s.at(j) == '1';
		}
	}

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			B[i][j] = s.at(j) == '1';
		}
	}

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			if (A[i][j] == B[i][j])
				continue;
			func(i, j);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] == B[i][j])
				continue;
			cout << -1;
			return 0;
		}
	}
	cout << ans;
}