#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int R, C, N;
bool m[101][101];
bool visited[101][101];
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

void fall(int r, int c)
{
	memset(visited, false, sizeof(visited));
	queue<int> q;
	vector<int> buffer;
	q.push(r);
	q.push(c);
	visited[r][c] = true;
	int cnt = 0;
	while (!q.empty())
	{
		cnt++;
		int curR = q.front();
		q.pop();
		int curC = q.front();
		q.pop();
		buffer.push_back(curR);
		buffer.push_back(curC);
		m[curR][curC] = false;
		for (int i = 0; i < 4; i++)
		{
			int nxtR = curR + dr[i];
			int nxtC = curC + dc[i];
			if (1 <= nxtR && nxtR <= R && 0 <= nxtC && nxtC < C && m[nxtR][nxtC] == true && visited[nxtR][nxtC] == false)
			{
				visited[nxtR][nxtC] = true;
				q.push(nxtR);
				q.push(nxtC);
			}
		}
	}

	int fallDist = 0x3f3f3f3f;
	int size = buffer.size();
	for (int i = 0; i < size; i+=2)
	{
		int curR = buffer[i];
		int curC = buffer[i + 1];
		int h = curR;
		while (h--)
		{
			if (h == 0) fallDist = min(fallDist, curR - 1);
			if (m[h][curC] == true)
			{
				fallDist = min(fallDist, curR - h - 1);
				break;
			}
		}
	}
	if (fallDist == 0x3f3f3f3f) fallDist = 0;
	for (int i = 0; i < size; i+=2)
	{
		int curR = buffer[i];
		int curC = buffer[i + 1];
		curR = curR - fallDist;
		m[curR][curC] = true;
	}
}

void shoot(int H, bool left)
{
	if (left)
	{
		for (int i = 0; i < C; i++)
		{
			if (m[H][i] != 0)
			{
				m[H][i] = false;
				if (H < R && m[H + 1][i] == true) fall(H + 1, i);
				if (1 < H && m[H - 1][i] == true) fall(H - 1, i);
				if (i + 1 < C && m[H][i + 1] == true) fall(H, i + 1);
				break;
			}
		}
	}
	else
	{
		for (int i = C - 1; i >= 0; i--)
		{
			if (m[H][i] != 0)
			{
				m[H][i] = false;
				if (H < R && m[H + 1][i] == true) fall(H + 1, i);
				if (1 < H && m[H - 1][i] == true) fall(H - 1, i);
				if(i - 1 >= 0 && m[H][i - 1] == true) fall(H, i - 1);
				break;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int i = R; i >= 1; i--)
	{
		string s;
		cin >> s;
		for (int j = 0; j < C; j++)
		{
			char c = s.at(j);
			if (c == 'x') m[i][j] = true;
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int H;
		cin >> H;
		shoot(H, i % 2 == 0);
	}
	for (int i = R; i >= 1; i--)
	{
		for (int j = 0; j < C; j++)
		{
			if (m[i][j] == true) cout << "x";
			else cout << ".";
		}
		cout << "\n";
	}
}