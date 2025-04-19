#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int t, n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;
            v.push_back(input);
        }

        sort(v.begin(), v.end());

        int s = 0, e = n - 1, near = INT32_MAX, cnt = 0;
        while (s < e)
        {
            int sum = v[s] + v[e];
            int ab = abs(k - sum);
            if (ab == near)
            {
                cnt++;
            }
            else if (ab < near)
            {
                cnt = 1;
                near = ab;
            }
            if (sum <= k)
                s++;
            if (sum >= k)
                e--;
        }
        cout << cnt << "\n";
    }
}