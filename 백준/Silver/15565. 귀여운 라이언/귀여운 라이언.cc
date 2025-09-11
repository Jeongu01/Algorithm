#include <iostream>
using namespace std;

int N, K;
int arr[1'000'000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int p1 = 0, p2 = 0, cnt = 0, ans = 0x3f3f3f3f;
	if (arr[0] == 1) cnt++;
	while (p1 < N && p2 < N)
	{
		if (cnt < K)
		{
			p2++;
			if (arr[p2] == 1) cnt++;
		}
		if (cnt >= K)
		{
			ans = min(ans, p2 - p1 + 1);
			if (arr[p1] == 1) cnt--;
			p1++;
		}
	}
	if (ans == 0x3f3f3f3f) cout << -1;
	else cout << ans;
}