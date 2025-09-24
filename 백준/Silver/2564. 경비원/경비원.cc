#include <iostream>
#include <vector>
using namespace std;

int N, M, T;
vector<int> pos[5];

int main()
{
    cin >> N >> M >> T;
    while (T--)
    {
        int dir, dist;
        cin >> dir >> dist;
        pos[dir].push_back(dist);
    }
    int dDir, dDist, ans = 0;
    cin >> dDir >> dDist;
    switch (dDir)
    {
    case 1:
        for (int dist : pos[1])
        {
            ans += abs(dDist - dist);
        }
        for (int dist : pos[2])
        {
            ans += min(dDist + M + dist, (N - dDist) + M + (N - dist));
        }
        for (int dist : pos[3])
        {
            ans += dDist + dist;
        }
        for (int dist : pos[4])
        {
            ans += (N - dDist) + dist;
        }
        break;
    case 2:
        for (int dist : pos[1])
        {
            ans += min(dDist + M + dist, (N - dDist) + M + (N - dist));
        }
        for (int dist : pos[2])
        {
            ans += abs(dDist - dist);
        }
        for (int dist : pos[3])
        {
            ans += dDist + (M - dist);
        }
        for (int dist : pos[4])
        {
            ans += (N - dDist) + (M - dist);
        }
        break;
    case 3:
        for (int dist : pos[1])
        {
            ans += dDist + dist;
        }
        for (int dist : pos[2])
        {
            ans += (M - dDist) + dist;
        }
        for (int dist : pos[3])
        {
            ans += abs(dDist - dist);
        }
        for (int dist : pos[4])
        {
            ans += min(dDist + N + dist, (M - dDist) + N + (M - dist));
        }
        break;
    case 4:
        for (int dist : pos[1])
        {
            ans += dDist + (N - dist);
        }
        for (int dist : pos[2])
        {
            ans += (M - dDist) + (N - dist);
        }
        for (int dist : pos[3])
        {
            ans += min(dDist + N + dist, (M - dDist) + N + (M - dist));
        }
        for (int dist : pos[4])
        {
            ans += abs(dDist - dist);
        }
        break;
    }
    cout << ans;
}