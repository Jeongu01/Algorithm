#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int N, M, cnt;
int arr[1001][1001];
int num[1001][1001];
map<int, int> m;
int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

void func(int r, int c)
{
    num[r][c] = cnt;
    m[cnt]++; 
    for (int i = 0; i < 4; i++)
    {
        int nextr = r + dr[i];
        int nextc = c + dc[i];
        if (0 <= nextr && nextr < N && 0 <= nextc && nextc < M && arr[nextr][nextc] == 0 && num[nextr][nextc] == 0)
        {
            func(nextr, nextc);
        }
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
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0 && num[i][j] == 0)
            {
                cnt++;
                func(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0) cout << "0";
            else
            {
                set<int> s;
                for (int k = 0; k < 4; k++)
                {
                    int r = i + dr[k];
                    int c = j + dc[k];
                    if (0 <= r && r < N && 0 <= c && c < M) s.insert(num[r][c]);
                }
                int ans = 1;
                for (int e : s)
                {
                    ans += m[e];
                }
                cout << ans % 10;
            }
        }
        cout << "\n";
    }
}