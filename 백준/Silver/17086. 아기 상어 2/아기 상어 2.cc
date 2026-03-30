#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, ans;
int arr[50][50];
queue<int> q;
bool visited[50][50];
int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int input;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = 0x3f3f3f3f;
            cin >> input;
            if (input == 1)
            {
                q.push(i);
                q.push(j);
                visited[i][j] = true;
                arr[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        int r = q.front(); q.pop();
        int c = q.front(); q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nxtr = r + dr[i];
            int nxtc = c + dc[i];
            if (nxtr < 0 || nxtr >= N || nxtc < 0 || nxtc >= M
                || visited[nxtr][nxtc] == true)
                continue;
            visited[nxtr][nxtc] = true;
            arr[nxtr][nxtc] = arr[r][c] + 1;
            q.push(nxtr);
            q.push(nxtc);
            ans = max(ans, arr[nxtr][nxtc]);
        }
    }
    cout << ans;
}