#include <iostream>
#include <queue>
using namespace std;

int N, M, cnt;
int arr[250][250];
bool visited[250][250];
int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void bfs(int r, int c)
{
    queue<int> q;
    q.push(r);
    q.push(c);
    visited[r][c] = true;
    while (!q.empty())
    {
        int curR = q.front(); q.pop();
        int curC = q.front(); q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nxtR = curR + dr[i];
            int nxtC = curC + dc[i];
            if (nxtR < 0 || nxtR >= N || nxtC < 0 || nxtC >= M) continue;
            if (visited[nxtR][nxtC] == true || arr[nxtR][nxtC] == 0) continue;
            visited[nxtR][nxtC] = true;
            q.push(nxtR);
            q.push(nxtC);
        }
    }
}

int main()
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
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j] == true || arr[i][j] == 0) continue;
            cnt++;
            bfs(i, j);
        }
    }
    cout << cnt;
}