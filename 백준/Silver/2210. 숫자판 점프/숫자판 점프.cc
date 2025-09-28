#include <iostream>
#include <set>
using namespace std;

int arr[5][5];
set<int> s;
int num;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void func(int depth, int r, int c)
{
	if (depth == 6)
	{
		s.insert(num);
		return;
	}
	num *= 10;
	num += arr[r][c];
	for (int i = 0; i < 4; i++)
	{
		int nxtR = r + dr[i];
		int nxtC = c + dc[i];
		if (0 <= nxtR && nxtR < 5 && 0 <= nxtC && nxtC < 5)
		{
			func(depth + 1, nxtR, nxtC);
		}
	}
	num /= 10;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			func(0, i, j);
		}
	}
	cout << s.size();
}