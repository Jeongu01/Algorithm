#include <iostream>
#include <queue>
using namespace std;

int N, M, D, ans;
bool arr[16][16], org[16][16];
int dr[] = { 0, -1, 0 };
int dc[] = { -1, 0, 1 };

pair<int, int> func(int pos)
{
    bool visited[16][16];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
        }
    }
    queue<int> q;
    q.push(N);
    q.push(pos);
    visited[N][pos] = true;
    int dist = 0;
    while (!q.empty())
    {
        int size = q.size();
        size /= 2;
        if (dist > D) break;
        dist++;
        while (size--)
        {
            int curR = q.front(); q.pop();
            int curC = q.front(); q.pop();
            if (arr[curR][curC] == true) return { curR, curC };
            for (int i = 0; i < 3; i++)
            {
                int nxtR = curR + dr[i];
                int nxtC = curC + dc[i];
                if (0 <= nxtR && nxtR < N && 0 <= nxtC && nxtC < M && visited[nxtR][nxtC] == false)
                {
                    visited[nxtR][nxtC] = true;
                    q.push(nxtR);
                    q.push(nxtC);
                }
            }
        }
    }
    return { -1, -1 };
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> D;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> org[i][j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = i + 1; j < M; j++)
        {
            for (int k = j + 1; k < M; k++)
            {
                for (int r = 0; r < N; r++)
                {
                    for (int c = 0; c < M; c++)
                    {
                        arr[r][c] = org[r][c];
                    }
                }
                int cnt = 0;
                for (int g = 0; g < N; g++)
                {
                    pair<int, int> p[3];
                    p[0] = func(i);
                    p[1] = func(j);
                    p[2] = func(k);
                    if (p[0].first != -1)
                    {
                        arr[p[0].first][p[0].second] = false;
                        cnt++;
                    }
                    if (p[1].first != -1 && arr[p[1].first][p[1].second] == true)
                    {
                        arr[p[1].first][p[1].second] = false;
                        cnt++;
                    }
                    if (p[2].first != -1 && arr[p[2].first][p[2].second] == true)
                    {
                        arr[p[2].first][p[2].second] = false;
                        cnt++;
                    }
                    for (int n = N - 1; n > 0; n--)
                    {
                        for (int m = 0; m < M; m++)
                        {
                            arr[n][m] = arr[n - 1][m];
                        }
                    }
                    for (int m = 0; m < M; m++)
                    {
                        arr[0][m] = false;
                    }
                }
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans;
}