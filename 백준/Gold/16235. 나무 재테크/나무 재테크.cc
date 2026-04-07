#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int N, M, K;
int org[11][11];
int arr[11][11];
deque<int> trees[11][11]; // front 에 늙은, back 에 어린
queue<int> dead[11][11];
int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void spring()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int size = trees[i][j].size();
            while (size--)
            {
                int cur = trees[i][j].back(); trees[i][j].pop_back();
                if (arr[i][j] < cur)
                {
                    dead[i][j].push(cur);
                }
                else
                {
                    arr[i][j] -= cur;
                    trees[i][j].push_front(cur + 1);
                }
            }
        }
    }
}

void summer()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            while (!dead[i][j].empty())
            {
                int cur = dead[i][j].front(); dead[i][j].pop();
                arr[i][j] += cur / 2;
            }
        }
    }
}

void fall()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int size = trees[i][j].size();
            while (size--)
            {
                int cur = trees[i][j].front();
                trees[i][j].pop_front();
                trees[i][j].push_back(cur);
                if (cur % 5 != 0) continue;
                for (int k = 0; k < 8; k++)
                {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (nr <= 0 || nr > N || nc <= 0 || nc > N)
                        continue;
                    trees[nr][nc].push_back(1);
                }
            }
        }
    }
}

void winter()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            arr[i][j] += org[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> org[i][j];
            arr[i][j] = 5;
        }
    }
    for (int i = 0; i < M; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        trees[x][y].push_back(z);
    }
    for (int i = 0; i < K; i++)
    {
        spring();
        summer();
        fall();
        winter();
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            ans += trees[i][j].size();
        }
    }
    cout << ans;
}