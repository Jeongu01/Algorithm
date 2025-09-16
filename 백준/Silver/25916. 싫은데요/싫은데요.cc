#include <iostream>
using namespace std;

int arr[500'000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int l = 0, r = 0, sum = 0, ans = 0;
	while (l < N && r < N)
	{
		sum += arr[r];
		r++;
		while (sum > M)
		{
			sum -= arr[l];
			l++;
		}
		ans = max(ans, sum);
	}
	cout << ans;
}