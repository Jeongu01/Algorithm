#include <iostream>
#include <queue>
using namespace std;

int arr[125][125];
int dist[125][125];
bool visited[125][125];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

struct Pos
{
	int r, c;
	Pos(int r, int c) : r(r), c(c) {}
	bool operator<(const Pos pos) const
	{
		return dist[this->r][this->c] > dist[pos.r][pos.c];
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 0;
	while (true)
	{
		int N;
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
				dist[i][j] = 0x3f3f3f3f;
				visited[i][j] = false;
			}
		}

		t++;
		priority_queue<Pos> pq;
		pq.push(Pos(0, 0));
		dist[0][0] = arr[0][0];
		visited[0][0] = true;
		while (!pq.empty())
		{
			Pos cur = pq.top();
			pq.pop();
			if (cur.r == N - 1 && cur.c == N - 1)
			{
				cout << "Problem " << t << ": " << dist[N - 1][N - 1] << "\n";
			}
			for (int i = 0; i < 4; i++)
			{
				int nxt_r = cur.r + dr[i];
				int nxt_c = cur.c + dc[i];
				if (0 <= nxt_r && nxt_r < N && 0 <= nxt_c && nxt_c < N && visited[nxt_r][nxt_c] == false)
				{
					visited[nxt_r][nxt_c] = true;
					dist[nxt_r][nxt_c] = min(dist[nxt_r][nxt_c], dist[cur.r][cur.c] + arr[nxt_r][nxt_c]);
					pq.push(Pos(nxt_r, nxt_c));
				}
			}
		}
	}
}