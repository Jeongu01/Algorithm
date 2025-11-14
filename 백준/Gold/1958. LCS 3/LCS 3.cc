#include <iostream>
using namespace std;

int arr[101][101][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            for (int k = 1; k <= len3; k++)
            {
                char c1 = s1.at(i - 1), c2 = s2.at(j - 1), c3 = s3.at(k - 1);
                if (c1 == c2 && c2 == c3) arr[i][j][k] = arr[i - 1][j - 1][k - 1] + 1;
                else arr[i][j][k] = max(max(arr[i - 1][j][k], arr[i][j - 1][k]), arr[i][j][k - 1]);
            }
        }
    }
    cout << arr[len1][len2][len3];
}