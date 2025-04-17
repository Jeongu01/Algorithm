#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
vector<int> arr[100001];
int answer[100001];
bool visited[100001];

int func(int n)
{
    visited[n] = true;

    int sum = 1, size = 0;
    for (int c : arr[n])
    {
        if (!visited[c])
        {
            sum += func(c);
            size++;
        }
    }
    return answer[n] = sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> R >> Q;
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    func(R);

    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        cout << answer[q] << "\n";
    }

    return 0;
}