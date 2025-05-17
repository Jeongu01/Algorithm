#include <iostream>
#include <map>
using namespace std;

int N, K;
int arr[200100];
map<int, int> pre;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	long long ans = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
		int t = arr[i] - K;
		ans += pre[t];
		if (arr[i] == K) ans++;
		pre[arr[i]]++;
	}
	cout << ans;
}