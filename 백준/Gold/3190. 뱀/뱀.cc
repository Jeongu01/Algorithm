#include <iostream>
#include <deque>
using namespace std;

int dir_idx = 0;
char dir[] = { 'R','D','L','U' };
int N, K, L, t = 1;
char arr[101][101];
bool finished;
deque<pair<int, int>> path;

void playing()
{
	auto cur = path.back();
	int nxt_r = cur.first, nxt_c = cur.second;

	switch (dir[dir_idx])
	{
	case 'R':
		nxt_c += 1;
		break;
	case 'L':
		nxt_c -= 1;
		break;
	case 'U':
		nxt_r -= 1;
		break;
	case 'D':
		nxt_r += 1;
		break;
	}
	if (0 < nxt_r && nxt_r <= N && 0 < nxt_c && nxt_c <= N && arr[nxt_r][nxt_c] != 'S')
	{
		if (arr[nxt_r][nxt_c] != 'A')
		{
			auto tail = path.front();
			arr[tail.first][tail.second] = 0;
			path.pop_front();
		}
		arr[nxt_r][nxt_c] = 'S';
		path.push_back(make_pair(nxt_r, nxt_c));
	}
	else
	{
		finished = true;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int r, c;
		cin >> r >> c;
		arr[r][c] = 'A';
	}

	path.push_back(make_pair(1, 1));
	arr[1][1] = 'S';

	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int X;
		char C;
		cin >> X >> C;

		for (;t <= X; t++)
		{
			playing();
			if (finished)
			{
				cout << t;
				return 0;
			}
		}

		if (C == 'D') dir_idx = (dir_idx + 1) % 4;
		else if (C == 'L' && dir_idx != 0) dir_idx = dir_idx - 1;
		else dir_idx = 3;
	}

	while (true)
	{
		playing();
		if (finished)
		{
			cout << t;
			return 0;
		}
		t++;
	}
}