#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long A, B;
    cin >> A >> B;
    cout << (A + B) * (A - B);
}