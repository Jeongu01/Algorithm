#include <iostream>
using namespace std;

int N;
int arr[1001];
int dp[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i] = min(dp[i], dp[i - j] + dp[j]);
        }
    }
    cout << dp[N];
}