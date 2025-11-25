#include <iostream>
using namespace std;

int arr[1'000'001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		arr[input] = i;
	}
	int maxLen = 1, len = 1, prev = arr[1];
	for (int i = 2; i <= n; i++)
	{
		if (prev < arr[i])
		{
			len++;
			maxLen = max(maxLen, len);
		}
		else
		{
			len = 1;
		}
		prev = arr[i];
	}
	cout << n - maxLen;
}