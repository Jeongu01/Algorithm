#include <iostream>
using namespace std;

int arr[1001][3][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int R, G, B;
    cin >> R >> G >> B;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            arr[1][i][j] = 0x3f3f3f3f;
    arr[1][0][0] = R;
    arr[1][1][1] = G;
    arr[1][2][2] = B;
    for (int i = 2; i <= N; i++)
    {
        cin >> R >> G >> B;
        for (int j = 0; j < 3; j++)
        {
            arr[i][j][0] = min(arr[i - 1][j][1], arr[i - 1][j][2]) + R;
            arr[i][j][1] = min(arr[i - 1][j][0], arr[i - 1][j][2]) + G;
            arr[i][j][2] = min(arr[i - 1][j][0], arr[i - 1][j][1]) + B;
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i != j) ans = min(ans, arr[N][i][j]);

    cout << ans;
}