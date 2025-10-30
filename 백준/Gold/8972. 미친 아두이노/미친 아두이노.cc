#include <iostream>
#include <queue>
using namespace std;

int R, C, cnt, Ir, Ic;
char board[101][101];
string cmd;
queue<pair<int, int>> Rs;

bool play(char dir)
{
	// 1. 이동
	int dr = 0, dc = 0;
	if (dir == '1' || dir == '2' || dir == '3') dr++;
	else if (dir == '7' || dir == '8' || dir == '9') dr--;
	if (dir == '1' || dir == '4' || dir == '7') dc--;
	else if (dir == '3' || dir == '6' || dir == '9') dc++;
	int nxtR = Ir + dr, nxtC = Ic + dc;
	// 2. 패배 케이스
	if (board[nxtR][nxtC] == 'R') return true;
	board[Ir][Ic] = '.';
	board[nxtR][nxtC] = 'I';
	Ir = nxtR; Ic = nxtC;
	// 3. 미친 아두이노 이동
	int size = Rs.size();
	while (size--)
	{ 
		auto pos = Rs.front(); Rs.pop(); Rs.push(pos);
		board[pos.first][pos.second] = '.'; 
	}
	size = Rs.size();
	while (size--)
	{
		auto pos = Rs.front(); Rs.pop();
		int Rr = pos.first, Rc = pos.second;
		int dr = 0, dc = 0;
		if (Ir > Rr) dr++;
		else if (Ir < Rr) dr--;
		if (Ic > Rc) dc++;
		else if (Ic < Rc) dc--;
		// 4. 패배 케이스
		int nxtR = Rr + dr, nxtC = Rc + dc;
		if (nxtR == Ir && nxtC == Ic) return true;
		else if (board[nxtR][nxtC] == 'R') board[nxtR][nxtC] = 'B';
		else if (board[nxtR][nxtC] == '.')
		{
			board[nxtR][nxtC] = 'R';
			Rs.push({ nxtR, nxtC });
		}
	}
	// 5. 폭발
	size = Rs.size();
	while (size--)
	{
		auto pos = Rs.front(); Rs.pop();
		if (board[pos.first][pos.second] == 'B') board[pos.first][pos.second] = '.';
		else Rs.push(pos);
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < C; j++)
		{
			char c = s.at(j);
			board[i][j] = c;
			if (c == 'I') { Ir = i; Ic = j; }
			else if (c == 'R') { Rs.push({ i, j }); }
		}
	}
	cin >> cmd;
	int idx = 0, len = cmd.length();
	bool isLose = false;
	for (int i = 0; i < len; i++)
	{
		isLose = play(cmd.at(idx));
		idx++;
		if (isLose) break;
	}
	if (isLose) cout << "kraj " << idx;
	else
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cout << board[i][j];
			}
			cout << "\n";
		}
	}
}