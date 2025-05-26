#include <iostream>
#include <map>
#include <set>
using namespace std;

int N, M;
// U D L R
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int arr[1000][1000];
bool isVisited[1000][1000];
pair<int, int> parents[1000][1000];
set<pair<int, int>> sp;

pair<int, int> f(int r, int c)
{
    pair<int, int> p = parents[r][c];
    if (p.first == r && p.second == c) return make_pair(r, c);
    return parents[r][c] = f(p.first, p.second);
}

void u(int r1, int c1, int r2, int c2)
{
    pair<int, int> p1 = parents[r1][c1];
    pair<int, int> p2 = parents[r2][c2];
    if (p1 != p2)
    {
        parents[p2.first][p2.second] = p1;
    }
}

void func(int r, int c)
{
    isVisited[r][c] = true;
    int dir = arr[r][c];
    int nextr = r + dr[dir];
    int nextc = c + dc[dir];
    if (0 <= nextr && nextr < N && 0 <= nextc && nextc < M)
    {
        if (f(nextr, nextc) != f(r, c)) u(nextr, nextc, r, c);
        if (!isVisited[nextr][nextc]) func(nextr, nextc);
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
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
        {
            switch (row.at(j))
            {
            case 'U':
                arr[i][j] = 0;
                break;
            case 'D':
                arr[i][j] = 1;
                break;
            case 'L':
                arr[i][j] = 2;
                break;
            case 'R':
                arr[i][j] = 3;
                break;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            parents[i][j] = make_pair(i, j);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!isVisited[i][j])
            {
                func(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            sp.insert(f(i, j));
        }
    }

    cout << sp.size();
}