#include <iostream>
#include <queue>
using namespace std;

int arr[201][201];
bool visited[201][201];
int dr[] = {-2, -2, 0, 0, 2, 2};
int dc[] = {-1, 1, -2, 2, -1, 1};
int N, sr, sc, er, ec, answer = -1;
bool arrived = false;

void bfs()
{
	queue<int> q;
	q.push(sr);
	q.push(sc);
	visited[sr][sc] = true;

	while (!q.empty() && !arrived)
	{
		int size = q.size();
		answer++;
		while (size)
		{
			size -= 2;
			int nr = q.front();
			q.pop();
			int nc = q.front();
			q.pop();

			if (nr == er && nc == ec)
			{
				arrived = true;
				break;
			}

			for (int i = 0; i < 6; i++)
			{
				int nextr = nr + dr[i];
				int nextc = nc + dc[i];

				if (0 <= nextr && nextr < N && 0 <= nextc && nextc < N && !visited[nextr][nextc])
				{
					visited[nextr][nextc] = true;
					q.push(nextr);
					q.push(nextc);
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> sr >> sc >> er >> ec;

	bfs();

	if (arrived)
		cout << answer;
	else
		cout << "-1";

	return 0;
}