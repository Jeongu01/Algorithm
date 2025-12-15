#include <iostream>
#include<queue>
using namespace std;

int w, h;
int arr[1000][1000];
bool visited[1000][1000];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> w >> h;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                visited[i][j] = false;
            }
        }
        string input;
        int x, y;
        queue<int> fire;
        for (int i = 0; i < h; i++)
        {
            cin >> input;
            for (int j = 0; j < w; j++)
            {
                arr[i][j] = input.at(j);
                if (arr[i][j] == '*')
                {
                    fire.push(i);
                    fire.push(j);
                }
                else if (arr[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
            }
        }

        queue<int> q;
        q.push(x);
        q.push(y);
        visited[x][y] = true;
        int cnt = 0;
        bool flag = false;
        while (!flag)
        {
            cnt++;
            int s = fire.size();
            s /= 2;
            while (s--)
            {
                int curR = fire.front(); fire.pop();
                int curC = fire.front(); fire.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nxtR = curR + dr[i];
                    int nxtC = curC + dc[i];
                    if (nxtR < 0 || nxtR >= h || nxtC < 0 || nxtC >= w) continue;
                    if (arr[nxtR][nxtC] == '.')
                    {
                        arr[nxtR][nxtC] = '*';
                        fire.push(nxtR);
                        fire.push(nxtC);
                    }
                }
            }

            int size = q.size();
            size /= 2;
            if (size == 0) break;
            while (size--)
            {
                int curR = q.front(); q.pop();
                int curC = q.front(); q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nxtR = curR + dr[i];
                    int nxtC = curC + dc[i];
                    if (nxtR < 0 || nxtR >= h || nxtC < 0 || nxtC >= w) flag = true;
                    if (visited[nxtR][nxtC] == true || arr[nxtR][nxtC] != '.') continue;
                    visited[nxtR][nxtC] = true;
                    q.push(nxtR);
                    q.push(nxtC);
                }
            }
        }

        if (!flag) cout << "IMPOSSIBLE\n";
        else cout << cnt << "\n";
    }
}