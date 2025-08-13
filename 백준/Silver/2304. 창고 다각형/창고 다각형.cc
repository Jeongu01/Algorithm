#include <iostream>
using namespace std;

int arr[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, top = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int L, H;
		cin >> L >> H;
		arr[L] = H;
		if (arr[top] < H) top = L;
	}

	int ans = 0, pre = arr[0], i = 0;
	while (true)
	{
		int cur = arr[i++];
		if (pre < cur) pre = cur;
		ans += pre;
		if (i == top) break;
	}
	int j = 1000;
	pre = arr[1000];
	while (true)
	{
		int cur = arr[j--];
		if (pre < cur) pre = cur;
		ans += pre;
		if (j == top) break;
	}
	cout << ans + arr[top];
}