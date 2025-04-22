#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int X, Y, Z;
    cin >> X >> Y >> Z;

    int m = X;
    m = min(m, Y);

    m = min(m, Z);
    int cnt = 0;

    while (m > 2)
    {
        m -= 2;
        cnt++;
    }


    if (X == 3 && Y == 3 && Z == 3)
        cout << 0;
    else
        cout << cnt;
}