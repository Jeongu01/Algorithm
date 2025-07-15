#include <iostream>
using namespace std;

int R[100'000];
long long dp[100'000][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> R[i];
    }

    dp[0][1] = R[0];
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + R[i];
    }
    long long ans = min(dp[N - 1][0], dp[N - 1][1]);
    cout << ans;
}