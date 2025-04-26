#include <iostream>
#include <queue>
using namespace std;

int parent[100001];
int N, M;

struct Edge
{
    int a, b, c;
    Edge(int A, int B, int C) : a(A), b(B), c(C) { }

    bool operator<(const Edge& e) const
    {
        return this->c > e.c;
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

    cin >> N >> M;
    priority_queue<Edge> pq;

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    long long sum = 0;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push(Edge(a, b, c));
        sum += c;
    }

    int cnt = 0;
    while (cnt < N - 1 && !pq.empty())
    {
        Edge now = pq.top();
        pq.pop();

        if (u(now.a, now.b))
        {
            cnt++;
            sum -= now.c;
        }
    }

    if (cnt == N - 1)
        cout << sum;
    else
        cout << -1;
}