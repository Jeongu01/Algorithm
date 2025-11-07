#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[1000][1000];
int dp[1000][1000];
bool visited[1000][1000];

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
    queue<int> q;
    q.push(0);
    q.push(0);
    dp[0][0] = arr[0][0];
    visited[0][0] = true;
    while (!q.empty())
    {
        int curR = q.front(); q.pop();
        int curC = q.front(); q.pop();
        if (curR + 1 < N)
        {
            dp[curR + 1][curC] = max(dp[curR + 1][curC], arr[curR + 1][curC] + dp[curR][curC]);
            if (visited[curR + 1][curC] == false)
            {
                q.push(curR + 1);
                q.push(curC);
                visited[curR + 1][curC] = true;
            }
        }
        if (curC + 1 < M)
        {
            dp[curR][curC + 1] = max(dp[curR][curC + 1], arr[curR][curC + 1] + dp[curR][curC]);
            if (visited[curR][curC + 1] == false)
            {
                q.push(curR);
                q.push(curC + 1);
                visited[curR][curC + 1] = true;
            }
        }
    }
    cout << dp[N - 1][M - 1];
}