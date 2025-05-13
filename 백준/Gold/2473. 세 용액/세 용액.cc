#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<long long> arr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());

	long long ans = 0x3f3f3f3f3f3f3f3f;
	int a1 = 0, a2 = 0, a3 = 0;
	for (int i = 0; i < N - 2; i++)
	{
		long long v = arr[i];
		int s = i + 1;
		int e = N - 1;
		while (s < e)
		{
			long long sum = v + arr[s] + arr[e];
			if (abs(ans) > abs(sum))
			{
				a1 = i;
				a2 = s;
				a3 = e;
				ans = sum;
			}
			if (sum >= 0) e--;
			else s++;
		}
	}
	cout << arr[a1] << " " << arr[a2] << " " << arr[a3];
}