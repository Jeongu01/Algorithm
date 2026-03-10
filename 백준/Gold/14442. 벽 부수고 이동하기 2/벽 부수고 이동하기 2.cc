#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, K;
bool arr[1001][1001];
int visited[1001][1001][11];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

struct st
{
    int r, c, w;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++)
        {
            arr[i][j] = s.at(j - 1) == '1';
        }
    }

    queue<st> q;
    q.push({ 1, 1, K });
    visited[1][1][K] = 1;
    int ans = -1;
    while (!q.empty())
    {
        int r = q.front().r;
        int c = q.front().c;
        int w = q.front().w;
        q.pop();
        if (r == N && c == M)
        {
            ans = visited[r][c][w];
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nxtR = r + dr[i];
            int nxtC = c + dc[i];
            if (nxtR < 1 || nxtR > N || nxtC < 1 || nxtC > M)
                continue;
            if (arr[nxtR][nxtC] == 1 && w > 0 && visited[nxtR][nxtC][w - 1] == 0)
            {
                q.push({ nxtR, nxtC, w - 1 });
                visited[nxtR][nxtC][w - 1] = visited[r][c][w] + 1;
            }
            if (arr[nxtR][nxtC] == 0 && visited[nxtR][nxtC][w] == 0)
            {
                q.push({ nxtR, nxtC, w });
                visited[nxtR][nxtC][w] = visited[r][c][w] + 1;
            }
        }
    }
    cout << ans;
}