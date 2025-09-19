#include <iostream>
#include <cmath>
using namespace std;

int N, M;
int arr[100'000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	
	long long l = 0, r = pow(10, 18), ans = 0x7fffffffffffffff;
	while (l <= r)
	{
		long long mid = (l + r) / 2;
		long long cnt = 0;
		for (int i = 0; i < N; i++)
		{
			cnt += mid / arr[i];
			if (cnt > M) break;
		}
		if (cnt >= M)
		{
			ans = min(ans, mid);
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << ans;
}