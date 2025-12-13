#include <iostream>
using namespace std;

int coins[100];
int dp[10'001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int coin = coins[i];
        for (int j = coin; j <= k; j++)
        {
            dp[j] += dp[j - coin];
        }
    }
    cout << dp[k];
}
