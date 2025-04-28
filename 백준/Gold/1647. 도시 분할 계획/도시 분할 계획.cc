#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, M;
int parent[100001];

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

struct Edge
{
    int a, b, c;
    Edge(int A, int B, int C) : a(A), b(B), c(C) {}
    bool operator<(const Edge& e) const
    {
        return this->c > e.c;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    priority_queue<Edge> pq;

    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        pq.push(Edge(A, B, C));
    }

    int cnt = 0, ans = 0, cut = 0;
    while (cnt < N - 1 && !pq.empty())
    {
        Edge now = pq.top();
        pq.pop();

        if (u(now.a, now.b))
        {
            cnt++;
            ans += now.c;
            cut = max(cut, now.c);
        }
    }

    cout << ans - cut;
}