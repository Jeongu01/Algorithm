#include <iostream>
using namespace std;

int parent[500000];
int n, m;

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

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    bool cycle = false;
    for (int i = 0; i < m; i++)
    {
        int p, q;
        cin >> p >> q;

        if (!u(p, q))
        {
            cout << i + 1;
            cycle = true;
            break;
        }
    }
    if (!cycle) cout << 0;
    
}