#include <iostream>
using namespace std;

int arr[100'001];
int team[100'001];
long long startNum, curNum, ans;

void func(int n)
{
    if (team[n] >= startNum)
    {
        ans += curNum - team[n];
        return;
    }
    if (team[n] != 0) return;
    team[n] = curNum;
    curNum++;
    func(arr[n]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        ans = 0, startNum = 1, curNum = 1;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            team[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            if (team[i] != 0) continue;
            startNum = curNum;
            func(i);
        }
        cout << n - ans << "\n";
    }
}