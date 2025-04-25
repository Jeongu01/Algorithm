#include <iostream>
#include <queue>
using namespace std;

int N, M, t;
int parent[10001];

struct Edge
{
    int A, B, C;
    Edge(int a, int b, int c) : A(a), B(b), C(c) { }

    bool operator<(const Edge& e) const
    {
        return this->C > e.C;
    }
};

int f(int a)
{
    if (a == parent[a]) return a;
    return parent[a] = f(parent[a]);
}

bool u(int a, int b)
{
    a = f(a);
    b = f(b);
    if (a != b)
    {
        parent[b] = a;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<Edge> pq;
    cin >> N >> M >> t;

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        pq.push(Edge(A, B, C));
    }

    int cnt = 0, ans = 0;
    while (cnt < N - 1 && !pq.empty())
    {
        Edge now = pq.top();
        pq.pop();

        if (u(now.A, now.B))
        {
            ans += now.C + cnt * t;
            cnt++;
        }
    }

    cout << ans;
}