#include <iostream>
#include <vector>
using namespace std;

int N, T;
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T;
    for (int i = 1; i <= T; i++)
    {
        if (T % i != 0) continue;
        v.push_back(i);
    }

    int ans = 0, a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        int m = 0x3f3f3f3f;
        for (int e : v)
        {
            m = min(m, abs(a - e));
        }
        ans += m;
    }

    cout << ans;
}