#include <iostream>
using namespace std;

int N, M;
int arr[20][20];
int T = 1, B = 6, R = 3, L = 4, U = 2, D = 5;
int dice[7];
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

void roll(int);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y, K;
    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    int cmd;
    while (K--)
    {
        cin >> cmd;
        int nxtX = x + dx[cmd];
        int nxtY = y + dy[cmd];
        if (nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= M) continue;
        x = nxtX;
        y = nxtY;
        roll(cmd);
        if (arr[x][y] == 0)
        {
            arr[x][y] = dice[B];
        }
        else
        {
            dice[B] = arr[x][y];
            arr[x][y] = 0;
        }
        cout << dice[T] << "\n";
    }
}

void roll(int cmd)
{
    int tmp = T;
    switch (cmd)
    {
    case 1:
        T = L;
        L = B;
        B = R;
        R = tmp;
        break;
    case 2:
        T = R;
        R = B;
        B = L;
        L = tmp;
        break;
    case 3:
        T = D;
        D = B;
        B = U;
        U = tmp;
        break;
    case 4:
        T = U;
        U = B;
        B = D;
        D = tmp;
        break;
    }
}