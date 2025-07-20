#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
bool arr[100][100];
bool visited[100][100];
int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int r1, c1, r2, c2;
        cin >> c1 >> r1 >> c2 >> r2;
        for (int r = r1; r < r2; r++)
        {
            for (int c = c1; c < c2; c++)
            {
                arr[r][c] = true;
            }
        }
    }

    int cnt = 0;
    vector<int> v;
    for (int r = 0; r < M; r++)
    {
        for (int c = 0; c < N; c++)
        {
            if (arr[r][c] == false && visited[r][c] == false)
            {
                cnt++;
                int size = 1;
                queue<int> q;
                q.push(r);
                q.push(c);
                visited[r][c] = true;
                while (!q.empty())
                {
                    int curR = q.front();
                    q.pop();
                    int curC = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int nxtR = curR + dr[i];
                        int nxtC = curC + dc[i];
                        if (0 <= nxtR && nxtR < M && 0 <= nxtC && nxtC < N && arr[nxtR][nxtC] == false && visited[nxtR][nxtC] == false)
                        {
                            visited[nxtR][nxtC] = true;
                            size++;
                            q.push(nxtR);
                            q.push(nxtC);
                        }
                    }
                }
                v.push_back(size);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << cnt << endl;
    for (int size : v)
    {
        cout << size << " ";
    }
}