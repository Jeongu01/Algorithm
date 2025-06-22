#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int K;
        cin >> K;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        while (K--)
        {
            int n;
            cin >> n;
            pq.push(n);
        }
        ll ans = 0;
        while (pq.size() > 1)
        {
            ll c1 = pq.top();
            pq.pop();
            ll c2 = pq.top();
            pq.pop();
            ll x = c1 + c2;
            ans += x;
            pq.push(x);
        }
        cout << ans << "\n";
    }
}