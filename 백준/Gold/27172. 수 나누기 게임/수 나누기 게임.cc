#include <iostream>
#include <map>
using namespace std;

int players[100001];
map<int, int> ans;
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        players[i] = x;
        ans[x] = 0;
    }

    for (int i = 1; i <= N; i++)
    {
        int k = 2;
        int p = players[i];
        while (p * k <= 1000000)
        {
            if (ans.find(p * k) != ans.end())
            {
                ans[p * k]--;
                ans[p]++;
            }
            k++;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << ans[players[i]] << " ";
    }
}