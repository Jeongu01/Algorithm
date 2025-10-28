#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int arr[601];

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
	int ans = 0x7f7f7f7f;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			int anna = arr[i] + arr[j];
			int s = 0, e = N - 1;
			while (s < e)
			{
				if (s == i || s == j) { s++; continue; }
				if (e == i || e == j) { e--; continue; }
				int h = arr[s] + arr[e];
				ans = min(ans, abs(anna - h));
				if (h < anna) s++;
				else e--;
			}
		}
	}
	cout << ans;
}