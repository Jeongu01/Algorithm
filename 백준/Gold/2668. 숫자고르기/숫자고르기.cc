#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N;
int arr[101];
bool visited[101];
bool finished[101];
vector<int> result;

void dfs(int cur, int st)
{
    visited[cur] = true;
    int nxt = arr[cur];
    if (visited[nxt] == false)
    {
        dfs(nxt, st);
    }
    else if (nxt == st)
    {
        result.push_back(st);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++)
    {
        memset(visited, false, sizeof(visited));
        dfs(i, i);
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for (auto e : result)
    {
        cout << e << "\n";
    }
}