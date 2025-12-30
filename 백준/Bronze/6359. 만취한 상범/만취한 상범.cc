#include <iostream>
#include <algorithm>
using namespace std;

bool rooms[100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k, n;
    cin >> k;
    while (k--)
    {
        cin >> n;
        fill(rooms, rooms + n, 1);
        for (int i = 2; i <= n; i++)
        {
            for (int j = i - 1; j < n; j+=i)
            {
                rooms[j] = !rooms[j];
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (rooms[i]) cnt++;
        }
        cout << cnt << "\n";
    }
}