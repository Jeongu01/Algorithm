#include <iostream>
using namespace std;

int N, M, K, ans = 0x3f3f3f3f;
int A[50][50];
int cmd[6][3];
bool used[6];

void turn(int r, int c, int s)
{
	for (int i = s; i > 0; i--)
	{
		int tmp = A[r - i][c - i];
		for (int j = r - i; j < r + i; j++)
			A[j][c - i] = A[j + 1][c - i];
		for (int j = c - i; j < c + i; j++)
			A[r + i][j] = A[r + i][j + 1];
		for (int j = r + i; j > r - i; j--)
			A[j][c + i] = A[j - 1][c + i];
		for (int j = c + i; j > c - i; j--)
			A[r - i][j] = A[r - i][j - 1];
		A[r - i][c - i + 1] = tmp;
	}
}

void func(int depth)
{
	if (depth == K)
	{
		for (int i = 0; i < N; i++)
		{
			int sum = 0;
			for (int j = 0; j < M; j++)
			{
				sum += A[i][j];
			}
			ans = min(ans, sum);
		}
	}

	int tmpArr[50][50];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			tmpArr[i][j] = A[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		if (used[i] == true) continue;
		used[i] = true;
		turn(cmd[i][0] - 1, cmd[i][1] - 1, cmd[i][2]);
		func(depth + 1);
		used[i] = false;
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < M; c++)
			{
				A[r][c] = tmpArr[r][c];
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < K; i++)
	{
		cin >> cmd[i][0] >> cmd[i][1] >> cmd[i][2];
	}
	func(0);
	cout << ans;
}