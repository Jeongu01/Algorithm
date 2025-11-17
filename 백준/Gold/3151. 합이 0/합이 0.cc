#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[10'001];

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
    sort(A, A + N);
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int trg = -(A[i] + A[j]);
            ans += upper_bound(A + j + 1, A + N, trg) - lower_bound(A + j + 1, A + N, trg);
        }
    }
    cout << ans;
}