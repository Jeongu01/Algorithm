#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[1000][1000];
bool visited[1000][1000];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void bfs(int r, int c)
{
    queue<int> q;
    visited[r][c] = true;
    q.push(r);
    q.push(c);
    while (!q.empty())
    {
        int curR = q.front(); q.pop();
        int curC = q.front(); q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nxtR = curR + dr[i];
            int nxtC = curC + dc[i];
            if (nxtR == -1) nxtR = N - 1;
            else if (nxtR == N) nxtR = 0;
            if (nxtC == -1) nxtC = M - 1;
            else if (nxtC == M) nxtC = 0;
            if (arr[nxtR][nxtC] == 1 || visited[nxtR][nxtC] == true) continue;
            visited[nxtR][nxtC] = true;
            q.push(nxtR);
            q.push(nxtC);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 1 || visited[i][j] == true) continue;
            ans++;
            bfs(i, j);
        }
    }

    cout << ans;
}