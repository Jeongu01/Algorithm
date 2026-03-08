#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100'001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        long long A, B;
        cin >> A >> B;
        arr[i] = B - A;
    }

    sort(arr, arr + N);

    cout << max(0LL, arr[K - 1]) << '\n';
    return 0;
}