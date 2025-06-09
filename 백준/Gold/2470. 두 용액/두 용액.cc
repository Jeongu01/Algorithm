#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int arr[100'000];

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

	int s = 0, e = N - 1, ans = 0x7f7f7f7f, ans1, ans2;
	while (s < e)
	{
		int sum = arr[s] + arr[e];
		if (abs(sum) < ans)
		{
			ans1 = arr[s];
			ans2 = arr[e];
			ans = abs(sum);
		}
		if (sum < 0)
		{
			s++;
		}
		else
		{
			e--;
		}
	}
	cout << ans1 << " " << ans2;
}