#include <iostream>
using namespace std;

/*
dp[1][7] =  dp[4][4] && dp[3][5] && dp[2][6]

dp[1][6] =  dp[2][5] && dp[3][4]
*/

int N, M;
int arr[2001];
bool dp[2001][2001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        dp[i][i] = true;
    }

    for (int i = 1; i + 1 <= N; i++)
    {
        dp[i][i + 1] = arr[i] == arr[i + 1];
    }

    for (int i = 3; i <= N; i++)    // 길이
    {
        for (int j = 1; j + i - 1 <= N; j++)    // 시작
        {
            int s = j;
            int e = j + i - 1;
            dp[s][e] = dp[s + 1][e - 1] && arr[s] == arr[e];
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] << "\n";
    }
}