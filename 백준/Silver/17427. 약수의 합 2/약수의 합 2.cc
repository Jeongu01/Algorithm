#include <iostream>
using namespace std;

int N;
int arr[1'000'001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j += i)
		{
			arr[j] += i;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= N; i++)
	{
		ans += arr[i];
	}
	cout << ans;
}