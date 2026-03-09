#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int>> dist[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a].push_back({ b, c });
        dist[b].push_back({ a, c });
    }

    while (M--)
    {
        int a, b;
        cin >> a >> b;
        bool flag = true;
        bool visited[1001];
        for (int i = 1; i <= N; i++)
        {
            visited[i] = false;
        }
        queue<int> q;
        q.push(a);
        q.push(0);
        visited[a] = true;
        while (!q.empty() && flag)
        {
            int node = q.front(); q.pop();
            int d = q.front(); q.pop();
            for (pair<int, int> p : dist[node])
            {
                int nxtD = d + p.second;
                if (p.first == b)
                {
                    cout << nxtD << "\n";
                    flag = false;
                    break;
                }
                if (visited[p.first] == true)
                    continue;
                visited[p.first] = true;
                q.push(p.first);
                q.push(nxtD);
            }
        }
    }
}