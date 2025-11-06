#include <iostream>
#include <set>
#include <queue>
using namespace std;

int trg = 123456780;
set<int> visited;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int makeInt(int arr[3][3])
{
    int ret = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ret *= 10;
            ret += arr[i][j];
        }
    }
    return ret;
}

void makeArr(int in, int out[3][3])
{
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 2; j >= 0; j--)
        {
            out[i][j] = in % 10;
            in /= 10;
        }
    }
}

void swap(int arr[3][3], int r1, int c1, int r2, int c2)
{
    int temp = arr[r1][c1];
    arr[r1][c1] = arr[r2][c2];
    arr[r2][c2] = temp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];

    int st = makeInt(arr);
    queue<int> q;
    q.push(st);
    visited.insert(st);
    int ans = -1, cnt = 0;
    bool flag = false;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int cur = q.front(); q.pop();
            if (cur == trg)
            {
                ans = cnt;
                flag = true;
                break;
            }
            int curArr[3][3];
            makeArr(cur, curArr);
            int zeroR, zeroC;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (curArr[i][j] != 0) continue;
                    zeroR = i;
                    zeroC = j;
                }
            }
            for (int i = 0; i < 4; i++)
            {
                int nxtR = zeroR + dr[i];
                int nxtC = zeroC + dc[i];
                if (0 <= nxtR && nxtR < 3 && 0 <= nxtC && nxtC < 3)
                {
                    swap(curArr, zeroR, zeroC, nxtR, nxtC);
                    int nxtVal = makeInt(curArr);
                    if (visited.find(nxtVal) == visited.end())
                    {
                        q.push(nxtVal);
                        visited.insert(nxtVal);
                    }
                    swap(curArr, zeroR, zeroC, nxtR, nxtC);
                }
            }
        }
        if (flag == true) break;
        cnt++;
    }
    cout << ans;
}