#include <iostream>
using namespace std;

int N, T;
int dp[101][10001];
int K[101];
int S[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T;
    for (int i = 1; i <= N; i++)
    {
        cin >> K[i] >> S[i];
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            if (j < K[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - K[i]] + S[i]);
        }
    }
    cout << dp[N][T];
}