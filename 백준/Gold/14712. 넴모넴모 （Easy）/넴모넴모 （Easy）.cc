#include <iostream>
using namespace std;

int N, M, answer = 1;	// 네모가 하나도 없을 때는 미리 추가
bool board[26][26];
int dr[] = { -1, -1, 1, 1 };
int dc[] = { -1, 1, -1, 1 };

bool checkSquare(int r, int c)
{
	bool ret = false;
	/*
	* [O] [X] [O]
	* [X] [V] [X]
	* [O] [X] [O]
	* O 부분이 있는지 확인, V는 (r,c)
	*/
	for (int i = 0; i < 4; i++)
	{
		int tempr = r + dr[i];
		int tempc = c + dc[i];

		if (0 < tempr && tempr <= N && 0 < tempc && tempc <= M)
		{
			ret |= board[r][c] && board[tempr][tempc] && board[r][tempc] && board[tempr][c];
		}
	}
	return !ret;
}

void squareSquare(int r, int c)
{
	int nextc = c + 1 > M ? 1 : c + 1;
	int nextr = c + 1 > M ? r + 1 : r;
	board[r][c] = true;
	bool canFinish = checkSquare(r, c);
	if (canFinish)
	{
		answer++;
		if (nextr <= N) squareSquare(nextr, nextc);
	}
	board[r][c] = false;
	if (nextr <= N) squareSquare(nextr, nextc);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	squareSquare(1, 1);

	cout << answer;

	return 0;
}