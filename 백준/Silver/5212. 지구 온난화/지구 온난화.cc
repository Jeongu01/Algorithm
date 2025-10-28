#include <iostream>
using namespace std;

int R, C;
bool arr[10][10];
bool ans[10][10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			char input;
			cin >> input;
			arr[r][c] = input == 'X';
		}
	}

	int dr[] = { -1, 1, 0, 0 };
	int dc[] = { 0, 0, -1, 1 };
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			if (arr[r][c] == false) continue;
			int cnt = 0;
			for (int i = 0; i < 4; i++)
			{
				int nR = r + dr[i];
				int nC = c + dc[i];
				if (nR < 0 || R <= nR || nC < 0 || C <= nC) cnt++;
				else if(arr[nR][nC] == false) cnt++;
			}
			if (cnt < 3) ans[r][c] = true;
		}
	}

	int top = 10, bottom = 0, left = 10, right = 0;
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			if (ans[r][c] == true)
			{
				top = min(top, r);
				bottom = max(bottom, r);
				left = min(left, c);
				right = max(right, c);
			}
		}
	}
	for (int r = top; r <= bottom; r++)
	{
		for (int c = left; c <= right; c++)
		{
			if (ans[r][c] == true) cout << "X";
			else cout << ".";
		}
		cout << "\n";
	}
}