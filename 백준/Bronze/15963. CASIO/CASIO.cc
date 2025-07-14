#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    cin >> n >> m;
    int ans = 0;
    if (n == m) ans = 1;
    cout << ans;
}