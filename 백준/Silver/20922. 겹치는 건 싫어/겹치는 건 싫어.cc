#include <iostream>
#include <map>
using namespace std;

int N, K;
int arr[200'000];
map<int, int> cnt;

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
	int s = 0, e = 0, ans = 0;
	while (e < N)
	{
		cnt[arr[e]]++;
		while (cnt[arr[e]] > K)
		{
			cnt[arr[s++]]--;
		}
		ans = max(ans, e - s);
		e++;
	}
	cout << ans + 1;
}