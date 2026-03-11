#include <iostream>
#include <queue>
using namespace std;

char arr[12][6];
bool visited[12][6];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

bool bfs(int r, int c)
{
    char color = arr[r][c];
    queue<int> q;
    q.push(r);
    q.push(c);
    visited[r][c] = true;
    queue<pair<int, int>> combo;
    combo.push({ r ,c });
    while (!q.empty())
    {
        int curR = q.front(); q.pop();
        int curC = q.front(); q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nxtR = curR + dr[i];
            int nxtC = curC + dc[i];
            if (nxtR < 0 || nxtR > 11 || nxtC < 0 || nxtC > 5
                || visited[nxtR][nxtC] == true || arr[nxtR][nxtC] != color)
                continue;
            combo.push({ nxtR, nxtC });
            q.push(nxtR);
            q.push(nxtC);
            visited[nxtR][nxtC] = true;
        }
    }
    if (combo.size() < 4)
        return false;
    while (!combo.empty())
    {
        auto p = combo.front(); combo.pop();
        arr[p.first][p.second] = '.';
    }
    return true;
}

void down()
{
    for (int i = 0; i < 6; i++)
    {
        int idx = 11;
        for (int j = 11; j >= 0; j--)
        {
            if (arr[j][i] == '.')
                continue;
            char tmp = arr[j][i];
            arr[j][i] = '.';
            arr[idx--][i] = tmp;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 12; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 6; j++)
        {
            arr[i][j] = s.at(j);
        }
    }

    bool flag = false;
    int ans = 0;
    while(true)
    {
        flag = false;
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 6; j++)
                visited[i][j] = false;

        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (arr[i][j] == '.' || visited[i][j])
                    continue;
                if (bfs(i, j) == false)
                    continue;
                flag |= true;
            }
        }
        down();
        if (flag == true)
            ans++;
        if (flag == false)
            break;
    }
    cout << ans;
}