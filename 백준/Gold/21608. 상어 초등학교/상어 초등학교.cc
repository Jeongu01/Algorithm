#include <iostream>
using namespace std;

int N;
int arr[21][21], like[401][4];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void calcPoint(int* pnt, int* emp, int n, int r, int c)
{
	for (int k = 0; k < 4; k++)
	{
		int nxtR = r + dr[k];
		int nxtC = c + dc[k];
		if (1 <= nxtR && nxtR <= N && 1 <= nxtC && nxtC <= N)
		{
			if (arr[nxtR][nxtC] == 0) (*emp)++;
			else
			{
				for (int l = 0; l < 4; l++)
				{
					if (arr[nxtR][nxtC] == like[n][l])
					{
						(*pnt)++;
						break;
					}
				}
			}
		}
	}
}

void setSeat(int n)
{
	int r = 0xff, c = 0xff, point = 0, emptySeat = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] != 0) continue;

			int tmpPoint = 0, tmpEmpty = 0;
			calcPoint(&tmpPoint, &tmpEmpty, n, i, j);
			if (point < tmpPoint)
			{
				r = i; c = j; point = tmpPoint; emptySeat = tmpEmpty;
			}
			else if (point == tmpPoint)
			{
				if (emptySeat < tmpEmpty)
				{
					r = i; c = j; point = tmpPoint; emptySeat = tmpEmpty;
				}
				else if (emptySeat == tmpEmpty)
				{
					if (r > i)
					{
						r = i; c = j; point = tmpPoint; emptySeat = tmpEmpty;
					}
					else if (r == i)
					{
						if (c > j)
						{
							r = i; c = j; point = tmpPoint; emptySeat = tmpEmpty;
						}
					}
				}
			}
		}
	}
	arr[r][c] = n;
}

int calcSum()
{
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int num = arr[i][j];
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int nxtR = i + dr[k];
				int nxtC = j + dc[k];
				if (1 <= nxtR && nxtR <= N && 1 <= nxtC && nxtC <= N)
				{
					int target = arr[nxtR][nxtC];
					for (int l = 0; l < 4; l++)
					{
						if (target == like[num][l])
						{
							cnt++;
							break;
						}
					}
				}
			}
			if (cnt == 1) sum += 1;
			else if (cnt == 2) sum += 10;
			else if (cnt == 3) sum += 100;
			else if (cnt == 4) sum += 1000;
		}
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N * N; i++)
	{
		int num;
		cin >> num;
		for (int j = 0; j < 4; j++)
		{
			cin >> like[num][j];
		}
		setSeat(num);
	}
	cout << calcSum();
}