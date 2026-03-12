#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int S;
    cin >> S;
    int cl = 0, now = 1, ans = 0;
    set<pair<int, int>> s;
    queue<pair<int, int>> q;
    q.push({ now, cl });
    while (true)
    {
        int size = q.size();
        while (size--)
        {
            auto cur = q.front(); q.pop();
            if (cur.first == S)
            {
                cout << ans;
                return 0;
            }
            if (cur.first > 0 && 
                s.find({ cur.first - 1, cur.second }) == s.end())
            {
                q.push({ cur.first - 1, cur.second });
                s.insert({ cur.first - 1, cur.second });
            }
            if (s.find({ cur.first, cur.first }) == s.end())
            {
                q.push({ cur.first, cur.first });
                s.insert({ cur.first, cur.first });
            }
            if (s.find({ cur.first + cur.second, cur.second }) == s.end())
            {
                q.push({ cur.first + cur.second, cur.second });
                s.insert({ cur.first + cur.second, cur.second });
            }
        }
        ans++;
    }
}