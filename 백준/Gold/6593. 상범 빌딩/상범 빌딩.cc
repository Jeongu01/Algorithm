#include <iostream>
#include <queue>
using namespace std;

int L, R, C, sl, sr, sc;
char B[30][30][30];
bool visited[30][30][30];
int dl[] = { -1, 1, 0, 0, 0, 0 };
int dr[] = { 0, 0, -1, 1, 0, 0 };
int dc[] = { 0, 0, 0, 0, -1, 1 };

int bfs()
{
    int t = 0;
    queue<int> q;
    q.push(sl);
    q.push(sr);
    q.push(sc);
    visited[sl][sr][sc] = true;
    while (!q.empty())
    {
        int size = q.size();
        size /= 3;
        t++;
        while (size--)
        {
            int cl = q.front(); q.pop();
            int cr = q.front(); q.pop();
            int cc = q.front(); q.pop();
            for (int i = 0; i < 6; i++)
            {
                int nl = cl + dl[i];
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                if (0 > nl || nl >= L || 0 > nr || nr >= R || 0 > nc || nc >= C) continue;
                if (B[nl][nr][nc] == 'E') return t;
                if (visited[nl][nr][nc] == false && B[nl][nr][nc] == '.')
                {
                    visited[nl][nr][nc] = true;
                    q.push(nl);
                    q.push(nr);
                    q.push(nc);
                }
            }
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;
        string input;

        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                cin >> input;
                for (int k = 0; k < C; k++)
                {
                    B[i][j][k] = input.at(k);
                    if (B[i][j][k] == 'S')
                    {
                        sl = i;
                        sr = j;
                        sc = k;
                        B[i][j][k] = '.';
                    }
                    visited[i][j][k] = false;
                }
            }
        }
        int ans = bfs();
        if (ans == 0) cout << "Trapped!\n";
        else cout << "Escaped in " << ans << " minute(s).\n";
    }
}