#include <iostream>
#include <algorithm>
using namespace std;

int arr[1'000'000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int left = 1, right = arr[N - 1], ans = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			sum += arr[i] / mid;
		}
		if (sum >= M)
		{
			ans = max(ans, mid);
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << ans;
}