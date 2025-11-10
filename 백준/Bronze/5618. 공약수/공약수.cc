#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int a = arr[n - 2];
	for (int i = 1; i <= a; i++)
	{
		bool b = true;
		for (int j = 0; j < n; j++)
		{
			if (arr[j] % i != 0) b = false;
		}
		if (b == true) cout << i << "\n";
	}
}