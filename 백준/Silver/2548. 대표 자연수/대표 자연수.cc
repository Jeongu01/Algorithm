#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[20'000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int ans = INT32_MAX, n = 0, pre = -1;
	for (int i = 0; i < N; i++)
	{
		if (pre == arr[i]) continue;
		pre = arr[i];
		int sum = 0;
		for (int j = 0; j < N; j++)
		{
			sum += abs(arr[i] - arr[j]);
			if (sum > ans) break;
		}
		if (sum < ans)
		{
			ans = sum;
			n = arr[i];
		}
	}
	cout << n;
}