#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

vector<int> arr[200'001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t, c;
        cin >> t >> c;
        arr[t].push_back(c);
    }
    for (int i = 1; i <= N; i++)
    {
        int size = pq.size();
        for (int e : arr[i])
        {
            if (size < i)
            {
                pq.push(e);
                size++;
            }
            else if (size == i)
            {
                if (pq.top() < e)
                {
                    pq.pop();
                    pq.push(e);
                }
            }
        }
    }
    int ans = 0;
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}