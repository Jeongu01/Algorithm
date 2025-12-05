#include <iostream>
using namespace std;

int N, M, homeCnt, chCnt, ans = 0x3f3f3f3f;
int homeR[100], homeC[100];
int chR[13], chC[13];
int dist[100][13];
bool visited[13];

void func(int idx, int depth)
{
    if (depth == M)
    {
        int sum = 0;
        for (int i = 0; i < homeCnt; i++)
        {
            int dst = 0x3f3f3f3f;
            for (int j = 0; j < chCnt; j++)
            {
                if (visited[j] == false) continue;
                dst = min(dst, dist[i][j]);
            }
            sum += dst;
        }
        ans = min(ans, sum);
        return;
    }
    for (int i = idx + 1; i < chCnt; i++)
    {
        if (visited[i] == true) continue;
        visited[i] = true;
        func(i, depth + 1);
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int input;
            cin >> input;
            if (input == 1)
            {
                homeR[homeCnt] = i;
                homeC[homeCnt] = j;
                homeCnt++;
            }
            else if (input == 2)
            {
                chR[chCnt] = i;
                chC[chCnt] = j;
                chCnt++;
            }
        }
    }
    for (int home = 0; home < homeCnt; home++)
    {
        for (int ch = 0; ch < chCnt; ch++)
        {
            dist[home][ch] = abs(homeR[home] - chR[ch]) + abs(homeC[home] - chC[ch]);
        }
    }

    for (int i = 0; i < chCnt; i++)
    {
        visited[i] = true;
        func(i, 1);
        visited[i] = false;
    }
    cout << ans;
}