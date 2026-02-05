#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N <= 10'000) cout << "Accepted";
    else cout << "Time limit exceeded";
}