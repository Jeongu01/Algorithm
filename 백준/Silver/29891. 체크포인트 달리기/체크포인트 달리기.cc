#include <iostream>
#include <algorithm>
using namespace std;

long long arr[200'000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);
    long long sum = 0;
    int i = 0;
    while (i < N && arr[i] < 0)
    {
        sum += -arr[i];
        i += K;
    }

    i = N - 1;
    while (i >= 0 && arr[i] > 0)
    {
        sum += arr[i];
        i -= K;
    }
    cout << sum * 2;
}