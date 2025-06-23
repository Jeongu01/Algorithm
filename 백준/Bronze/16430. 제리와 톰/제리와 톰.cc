#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B;
    cin >> A >> B;
    A = B - A;
    for (int i = 2; i < A && i < B; i++)
    {
        if (A % i == 0 && B % i == 0)
        {
            A /= i;
            B /= i;
        }
    }
    cout << A << " " << B;
}