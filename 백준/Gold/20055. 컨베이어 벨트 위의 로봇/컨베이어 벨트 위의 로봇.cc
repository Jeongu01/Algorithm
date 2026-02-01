#include <iostream>
#include <queue>
using namespace std;

int N, K, s, e, cnt;
int arr[200];
bool robot[200];
queue<int> pos;

void turnBelt()
{
    s = s == 0 ? N + N - 1 : s - 1;
    e = e == 0 ? N + N - 1 : e - 1;
}

void moveRobot()
{
    int size = pos.size();
    while (size--)
    {
        int p = pos.front(); pos.pop();
        if (p == (s + N - 1) % (N + N))
        {
            robot[p] = false;
            continue;
        }
        int nxt = (p + 1) % (N + N);
        if (arr[nxt] == 0 || robot[nxt] == true)
        {
            pos.push(p);
            continue;
        }
        robot[p] = false;
        arr[nxt]--;
        if (arr[nxt] == 0)
            cnt++;
        if (nxt == (s + N - 1) % (N + N))
        {
            robot[nxt] = false;
            continue;
        }
        robot[nxt] = true;
        pos.push(nxt);
    }
}

void putRobot()
{
    if (arr[s] == 0 || robot[s] == true) return;
    robot[s] = true;
    pos.push(s);
    arr[s]--;
    if (arr[s] == 0)
        cnt++;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    s = 0;
    e = N + N - 1;
    for (int i = 0; i <= e; i++)
    {
        cin >> arr[i];
    }
    int turn = 0;
    while (cnt < K)
    {
        turn++;
        turnBelt();
        moveRobot();
        putRobot();
    }
    cout << turn;
}