#include <iostream>
using namespace std;

int N, H = -1;
int arr[100][100];
bool visited[100][100];
int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

void func(int r, int c)
{
    if (visited[r][c])
    {
        return;
    }
    visited[r][c] = true;
    for (int i = 0; i < 4; i++)
    {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        if (0 <= next_r && next_r < N && 0 <= next_c && next_c < N)
        {
            if (!visited[next_r][next_c] && arr[next_r][next_c] > H)
            {
                func(next_r, next_c);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    while (++H <= 100)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                visited[i][j] = false;
            }
        }
        int area = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j] && arr[i][j] > H)
                {
                    area++;
                    func(i, j);
                }
            }
        }
        ans = max(ans, area);
    }
    cout << ans;
}