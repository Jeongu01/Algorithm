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
            int lower_idx = 0, upper_idx = 0;
            int left = j + 1, right = N, mid;
            int trg = -(A[i] + A[j]);
            while (left < right)
            {
                mid = (left + right) / 2;
                if (A[mid] >= trg) right = mid;
                else left = mid + 1;
            }
            lower_idx = left;
            left = j + 1, right = N;
            while (left < right)
            {
                mid = (left + right) / 2;
                if (A[mid] > trg) right = mid;
                else left = mid + 1;
            }
            upper_idx = left;
            ans += upper_idx - lower_idx;
        }
    }
    cout << ans;
}