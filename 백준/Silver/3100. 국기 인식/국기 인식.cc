#include <iostream>
using namespace std;

char arr[6][9];
int rowCnt[3][26];
int colCnt[3][26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 6; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++)
        {
            arr[i][j] = s.at(j);
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int idx = arr[i][j] - 'A';
            rowCnt[i / 2][idx]++;
            colCnt[j / 3][idx]++;
        }
    }

    int ans = 0x3f3f3f3f;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (i == j) continue;
            for (int k = 0; k < 26; k++)
            {
                if (j == k) continue;
                int cost = 54 - rowCnt[0][i] - rowCnt[1][j] - rowCnt[2][k];
                ans = min(ans, cost);
                cost = 54 - colCnt[0][i] - colCnt[1][j] - colCnt[2][k];
                ans = min(ans, cost);
            }
        }
    }
    cout << ans;
}