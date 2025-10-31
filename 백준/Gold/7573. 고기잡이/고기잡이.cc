#include <iostream>
#include <vector>
using namespace std;

int N, M, l, ans;
bool arr[10'001][10'001];
vector<pair<int, int>> poses;

void search(int r, int c, int width, int height)
{
    int cnt = 0;
    if (r < 1 || c < 1) return;
    if (r + height > N) height = N - r;
    if (c + width > N) width = N - c;
    for (int i = r; i <= r + height; i++)
    {
        for (int j = c; j <= c + width; j++)
        {
            cnt += arr[i][j];
        }
    }
    ans = max(ans, cnt);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> l >> M;
    for (int i = 0; i < M; i++)
    {
        int r, c;
        cin >> r >> c;
        arr[r][c] = true;
        poses.push_back({ r, c });
    }
    l /= 2;
    for (int i = 1; i < l; i++)
    {
        int width = i, height = l - i;
        for (auto pos : poses)
        {
            for (int k = 0; k <= width; k++) search(pos.first, pos.second - k, width, height);
            for (int k = 0; k <= height; k++) search(pos.first - k, pos.second, width, height);
        }
    }
    cout << ans;
}