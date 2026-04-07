#include <iostream>
using namespace std;

bool v;
int N, M, R;
int arr[300][300];
int ans[300][300];

int sr, sc, er, ec, tr, tc;
void moveTargetPos()
{
    if (tr == sr && tc == sc) tc++;
    else if (tr == sr && tc == ec) tr++;
    else if (tr == er && tc == ec) tc--;
    else if (tr == er && tc == sc) tr--;
    else if (tr == sr) tc++;
    else if (tc == ec) tr++;
    else if (tr == er) tc--;
    else if (tc == sc) tr--;
}

void turn(int depth)
{
    sr = depth, sc = depth, er = N - depth - 1, ec = M - depth - 1;
    int len = (er - sr) * 2 + (ec - sc) * 2;
    int dist = R % len;
    tr = sr, tc = sc + dist;
    if (ec < tc)
    {
        tr += dist - (ec - sc);
        tc = ec;
        if (er < tr)
        {
            tc -= dist - (ec - sc) - (er - sr);
            tr = er;
            if (tc < sc)
            {
                tr -= dist - (ec - sc) - (er - sr) - (ec - sc);
                tc = sc;
            }
        }
    }
    for (int i = sc; i < ec; i++)
    {
        ans[sr][i] = arr[tr][tc];
        moveTargetPos();
    }
    for (int i = sr; i < er; i++)
    {
        ans[i][ec] = arr[tr][tc];
        moveTargetPos();
    }
    for (int i = ec; i > sc; i--)
    {
        ans[er][i] = arr[tr][tc];
        moveTargetPos();
    }
    for (int i = er; i > sr; i--)
    {
        ans[i][sc] = arr[tr][tc];
        moveTargetPos();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R;
    v = N <= M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    int depth = min(N, M) / 2;
    for (int k = 0; k < depth; k++)
    {
        turn(k);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}