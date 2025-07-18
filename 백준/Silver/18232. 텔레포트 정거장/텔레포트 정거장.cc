#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, S, E;
vector<int> tp[300'001];
bool visited[300'001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> S >> E;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        tp[x].push_back(y);
        tp[y].push_back(x);
    }

    queue<int> q;
    q.push(S);
    int ans = -1;
    while (!q.empty())
    {
        int size = q.size();
        ans++;
        while (size--)
        {
            int cur = q.front();
            q.pop();
            if (cur == E)
            {
                cout << ans;
                return 0;
            }

            visited[cur] = true;
            if (cur - 1 > 0 && visited[cur - 1] == false)
            {
                q.push(cur - 1);
            }
            if (cur + 1 <= N && visited[cur + 1] == false) q.push(cur + 1);
            for (int nxt : tp[cur])
            {
                if (visited[nxt] == false) q.push(nxt);
            }
        }
    }
}