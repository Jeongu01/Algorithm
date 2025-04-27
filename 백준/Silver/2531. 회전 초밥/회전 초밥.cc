#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N, d, k, c;
int eat[3001];
int arr[30000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++)
	{
		int type;
		cin >> type;
		arr[i] = type;
	}

	int cnt = 0;
	for (int i = 0; i < k; i++)
	{
		int now = arr[i];
		if (now != c && eat[now]++ == 0)
			cnt++;
	}

	int ans = cnt;
	for (int start = 0; start < N; start++)
	{
		int now = arr[start];
		if (now != c && --eat[now] == 0)
			cnt--;

		int index = (start + k) % N;
		int next = arr[index];
		if (next != c && eat[next]++ == 0)
			cnt++;

		ans = max(ans, cnt);
	}

	cout << ans + 1;

	return 0;
}