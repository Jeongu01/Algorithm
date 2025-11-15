#include <iostream>
using namespace std;

int N;
int A[1'000'000];
int dp[1'000'000];

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
	int len = 1;
	dp[0] = A[0];
	for (int i = 1; i < N; i++)
	{
		if (dp[len - 1] < A[i])
		{
			dp[len] = A[i];
			len++;
			continue;
		}
		int start = 0, end = len, mid;
		while (start < end)
		{
			mid = (start + end) / 2;
			if (dp[mid] < A[i]) start = mid + 1;
			else end = mid;
		}
		dp[start] = A[i];
	}
	cout << len;
}