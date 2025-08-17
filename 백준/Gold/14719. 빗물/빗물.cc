#include <iostream>

using namespace std;

int H, W;
int height[501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W;
    for (int i = 0; i < W; i++)
    {
        cin >> height[i];
    }
    int s = 0, e = 1, pre = 0, ans = 0;
    while (e < W)
    {
        if (height[s] <= height[e])
        {
            for (int i = s + 1; i < e; i++)
            {
                ans += height[s] - height[i];
            }
            s = e;
        }
        else if (height[pre] < height[e])
        {
            for (int i = s + 1; i < e; i++)
            {
                if (height[e] > height[i])
                {
                    ans += height[e] - height[i];
                    height[i] = height[e];
                }
            }
        }
        pre++;
        e++;
    }
    if (height[s] > height[W - 1])
    {
        for (int i = s + 1; i < W - 1; i++)
        {
            ans += max(0, height[W - 1] - height[i]);
        }
    }
    cout << ans;
}