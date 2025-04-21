#include <iostream>
#include <vector>
using namespace std;

bool found = false;
int arr[9][9];
vector<pair<int, int>> blanks;

bool checkCol(int r, int c)
{

	int temp = arr[r][c];
	for (int i = 0; i < 9; i++)
		if (arr[i][c] == temp && i != r) return false;
	return true;
}

bool checkBox(int r, int c)
{
	int boxR = r / 3;
	int boxC = c / 3;

	int temp = arr[r][c];
	for (int i = 3 * boxR; i < 3 * (boxR + 1); i++)
		for (int j = 3 * boxC; j < 3 * (boxC + 1); j++)
			if (arr[i][j] == temp && (i != r || j != c)) return false;
	return true;
}

bool checkRow(int r, int c)
{
	int temp = arr[r][c];
	for (int i = 0; i < 9; i++)
		if (arr[r][i] == temp && i != c) return false;
	return true;
}

void printBoard()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}
	found = true;
}

void play(int idx, int size)
{
	if (idx == size)
	{
		printBoard();
		return;
	}
	pair<int, int> now = blanks[idx];
	int r = now.first;
	int c = now.second;
	for (int i = 1; i <= 9; i++)
	{
		arr[r][c] = i;
		if (!checkRow(r, c)) continue;
		if (!checkBox(r, c)) continue;
		if (!checkCol(r, c)) continue;
		play(idx + 1, size);
		if (found) return;
	}
	arr[r][c] = 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	for (int i = 0; i < 9; i++)
	{
		cin >> s;
		for (int j = 0; j < 9; j++)
		{
			arr[i][j] = s.at(j) - '0';
			if (arr[i][j] == 0)
			{
				blanks.push_back(make_pair(i, j));
			}
		}
	}

	play(0, blanks.size());

	return 0;
}