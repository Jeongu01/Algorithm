#include <iostream>
#include <cstring>
using namespace std;

bool isValid;
char board[3][3];

bool whoWin(char c)
{
	if (board[1][1] == c)
	{
		if (board[0][0] == c && board[2][2] == c) return true;
		if (board[0][1] == c && board[2][1] == c) return true;
		if (board[0][2] == c && board[2][0] == c) return true;
		if (board[1][0] == c && board[1][2] == c) return true;
	}
	else
	{
		if (board[0][0] == c && board[0][1] == c && board[0][2] == c) return true;
		if (board[2][0] == c && board[2][1] == c && board[2][2] == c) return true;
		if (board[0][0] == c && board[1][0] == c && board[2][0] == c) return true;
		if (board[0][2] == c && board[1][2] == c && board[2][2] == c) return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		string input;
		cin >> input;
		if (!strcmp("end", input.c_str())) break;
		int cnt_X = 0, cnt_O = 0;
		isValid = true;
		for (int i = 0; i < 9; i++)
		{
			char c = input.at(i);
			board[i / 3][i % 3] = c;
			if (c == 'X') cnt_X++;
			else if (c == 'O') cnt_O++;
		}

		if (cnt_X == cnt_O)
		{
			if (!whoWin('O') || whoWin('X')) isValid = false;
		}
		else if (cnt_X == cnt_O + 1)
		{
			if (cnt_X + cnt_O == 9)
			{
				if (whoWin('O')) isValid = false;
			}
			else
			{
				if (!whoWin('X') || whoWin('O')) isValid = false;
			}
		}
		else
		{
			isValid = false;
		}
		if (isValid) cout << "valid\n";
		else cout << "invalid\n";
	}
}