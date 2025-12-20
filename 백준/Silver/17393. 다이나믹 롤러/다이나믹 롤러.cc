#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long A[500'000];
long long B[500'000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++)
    {
        cout << upper_bound(B + i + 1, B + N, A[i]) - (B + i + 1) << " ";
    }
}