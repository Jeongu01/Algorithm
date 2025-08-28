#include <iostream>
#include <deque>
using namespace std;

int N, M, r1, c1, r2, c2, cnt;
int arr[300][300];
bool visited[300][300];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
deque<pair<int, int>> d;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> r1 >> c1 >> r2 >> c2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c;
			cin >> c;
			arr[i][j] = c - '0';
		}
	}
	r1--; c1--; r2--; c2--;
	d.push_front({ r1, c1 });
	visited[r1][c1] = true;
	while (!d.empty())
	{
		int size = d.size();
		cnt++;
		while (size--)
		{
			auto cur = d.front();
			d.pop_front();
			for (int i = 0; i < 4; i++)
			{
				int nxt_x = cur.first + dr[i];
				int nxt_y = cur.second + dc[i];
				if (nxt_x == r2 && nxt_y == c2)
				{
					cout << cnt;
					return 0;
				}
				if (0 <= nxt_x && nxt_x < N && 0 <= nxt_y && nxt_y < M && !visited[nxt_x][nxt_y])
				{
					visited[nxt_x][nxt_y] = true;
					if (arr[nxt_x][nxt_y] == 0)
					{
						d.push_front({ nxt_x, nxt_y });
						size++;
					}
					else if (arr[nxt_x][nxt_y] == 1) d.push_back({ nxt_x, nxt_y });
				}
			}
		}
	}
}