#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[300][300];
int m[300][300];
bool visited[300][300];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void melt();
void bfs(int, int);

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

    int cnt = 0;
    while (true)
    {
        bool b = false;
        int r = -1, c = -1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (arr[i][j] == 0) continue;
                b = true;
                r = i;
                c = j;
                break;
            }
            if (b == true) break;
        }
        if (r == -1 && c == -1)
        {
            cout << 0;
            return 0;
        }
        bfs(r, c);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (arr[i][j] == 0 || visited[i][j] == true) continue;
                cout << cnt;
                return 0;
            }
        }
        melt();
        cnt++;
    }
}

void melt()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (m[i][j] == 0) continue;
            arr[i][j] = max(arr[i][j] - m[i][j], 0);
            m[i][j] = 0;
        }
    }
}

void bfs(int r, int c)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
        }
    }

    queue<int> q;
    q.push(r);
    q.push(c);
    visited[r][c] = true;
    while (!q.empty())
    {
        int size = q.size();
        size /= 2;
        while (size--)
        {
            int curR = q.front(); q.pop();
            int curC = q.front(); q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nxtR = curR + dr[i];
                int nxtC = curC + dc[i];
                if (arr[nxtR][nxtC] == 0) m[curR][curC]++;
            }
            for (int i = 0; i < 4; i++)
            {
                int nxtR = curR + dr[i];
                int nxtC = curC + dc[i];
                if (arr[nxtR][nxtC] == 0 || visited[nxtR][nxtC] == true) continue;
                visited[nxtR][nxtC] = true;
                q.push(nxtR);
                q.push(nxtC);
            }
        }
    }
}