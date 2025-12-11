#include <iostream>
#include<queue>
using namespace std;

int N, M;
int arr[100][100];
int C[100][100];
bool visited[100][100];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

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
        cnt++;
        queue<int> q;
        q.push(0);
        q.push(0);
        visited[0][0] = true;
        while (!q.empty())
        {
            int curR = q.front(); q.pop();
            int curC = q.front(); q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nxtR = curR + dr[i];
                int nxtC = curC + dc[i];
                if (nxtR < 0 || nxtR >= N || nxtC < 0 || nxtC >= M) continue;
                if (arr[nxtR][nxtC] == 1)
                {
                    C[nxtR][nxtC]++;
                    continue;
                }
                if (visited[nxtR][nxtC] == true) continue;
                visited[nxtR][nxtC] = true;
                q.push(nxtR);
                q.push(nxtC);
            }
        }
        bool isExist = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (C[i][j] >= 2) arr[i][j] = 0;
                C[i][j] = 0;
                visited[i][j] = false;
                if (arr[i][j] == 1) isExist = true;
            }
        }
        if (!isExist) break;
    }
    cout << cnt;
}