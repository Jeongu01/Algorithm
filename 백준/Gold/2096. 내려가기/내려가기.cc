#include <iostream>
using namespace std;

bool b = false;
int N;
int arr[100'001][3];
int maxDp[2][3], minDp[2][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    maxDp[b][0] = arr[0][0]; maxDp[b][1] = arr[0][1]; maxDp[b][2] = arr[0][2];
    minDp[b][0] = arr[0][0]; minDp[b][1] = arr[0][1]; minDp[b][2] = arr[0][2];
    for (int i = 1; i < N; i++)
    {
        maxDp[!b][0] = max(maxDp[b][0], maxDp[b][1]) + arr[i][0];
        maxDp[!b][1] = max(max(maxDp[b][0], maxDp[b][1]), maxDp[b][2]) + arr[i][1];
        maxDp[!b][2] = max(maxDp[b][1], maxDp[b][2]) + arr[i][2];
        minDp[!b][0] = min(minDp[b][0], minDp[b][1]) + arr[i][0];
        minDp[!b][1] = min(min(minDp[b][0], minDp[b][1]), minDp[b][2]) + arr[i][1];
        minDp[!b][2] = min(minDp[b][1], minDp[b][2]) + arr[i][2];
        b = !b;
    }

    int maxAns = 0, minAns = 0x3f3f3f3f;
    for (int i = 0; i < 3; i++)
    {
        maxAns = max(maxAns, maxDp[b][i]);
        minAns = min(minAns, minDp[b][i]);
    }

    cout << maxAns << " " << minAns;
}