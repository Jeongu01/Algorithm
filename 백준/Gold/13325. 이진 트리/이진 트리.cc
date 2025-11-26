#include <iostream>
using namespace std;

int k;
int arr[3'000'000], org[3'000'000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> k;
	int n = 1, i = 0;
	while (i < k + 1)
	{
		n *= 2;
		i++;
	}
	n--;
	for (int i = 2; i <= n; i++)
	{
		cin >> arr[i];
		org[i] = arr[i];
	}
	for (int i = n; i > 2; i -= 2)
	{
		if (org[i] > org[i - 1])
		{
			arr[i - 1] += org[i] - org[i - 1];
			org[i / 2] += org[i];
		}
		else
		{
			arr[i] += org[i - 1] - org[i];
			org[i / 2] += org[i - 1];
		}
	}
	long long ans = 0;
	for (int i = 2; i <= n; i++)
	{
		ans += arr[i];
	}
	cout << ans;
}