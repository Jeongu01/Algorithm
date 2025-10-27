#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int pre, pre_cnt = 0;
    long long ans = 0;
    cin >> pre;
    for (int i = 1; i < N; i++)
    {
        int cur, cur_cnt = 0;
        cin >> cur;
        cur_cnt = max((int)ceil(log2((double)pre / (double)cur)) + pre_cnt, 0);
        ans += cur_cnt;
        pre = cur;
        pre_cnt = cur_cnt;
    }
    cout << ans;
}