#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    double a = (d1 + d2 - d3) / 2.0;
    double b = (d1 + d3 - d2) / 2.0;
    double c = (d2 + d3 - d1) / 2.0;
    if (a <= 0 || b <= 0 || c <= 0)
    {
        printf("-1");
        return 0;
    }
    printf("1\n");
    printf("%.1f %.1f %.1f", a, b, c);
}