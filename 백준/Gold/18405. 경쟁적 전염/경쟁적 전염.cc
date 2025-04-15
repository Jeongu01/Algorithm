#include <iostream>
#include <queue>
using namespace std;

int N, K, S, X, Y;
int arr[201][201];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

struct Pos
{
    int x, y, num;
    Pos(int x, int y, int num) : x(x), y(y), num(num) {}

    bool operator<(const Pos p) const {
        return this->num > p.num;
    }
};

priority_queue<Pos> pq;
queue<Pos> q;

void bfs()
{
    while (S--)
    {
        int size = q.size();
        while (size--)
        {
            Pos now = q.front();
            q.pop();
            int now_x = now.x;
            int now_y = now.y;
            for (int i = 0; i < 4; i++)
            {
                int next_x = now_x + dx[i];
                int next_y = now_y + dy[i];
                if (0 < next_x && next_x <= N && 0 < next_y && next_y <= N)
                {
                    if (arr[next_x][next_y] == 0)
                    {
                        arr[next_x][next_y] = now.num;
                        q.push(Pos(next_x, next_y, now.num));
                    }
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j]) pq.push(Pos(i, j, arr[i][j]));
        }
    }

    cin >> S >> X >> Y;
    while (!pq.empty())
    {
        q.push(pq.top());
        pq.pop();
    }

    bfs();
    cout << arr[X][Y];

    return 0;
}