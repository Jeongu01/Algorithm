#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;
vector<pair<int, int>> b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < K; i++)
    {
        int v, c;
        cin >> v >> c;
        b.push_back({ c, v });
    }
    sort(b.begin(), b.end());
    priority_queue<int> pq;
    long long sum = 0;
    for (auto cv : b)
    {
        pq.push(-cv.second);

        sum += cv.second;

        if (pq.size() > N)
        {
            sum += pq.top();
            pq.pop();
        }

        if (pq.size() == N && sum >= M)
        {
            cout << cv.first;
            return 0;
        }
    }
    cout << "-1";
}