#include <iostream>
#include <set>
using namespace std;

int n, k;
set<int> coins;
int arr[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int price;
		cin >> price;
		if (price <= 10000) coins.insert(price);
	}

	for (int p : coins)
	{
		for (int i = p; i <= k; i++)
		{
			for (int t = p; t <= i; t+=p)
			{
				if (i - t == 0)
				{
					if (arr[i] == 0) arr[i] = t / p;
					else arr[i] = min(arr[i], t / p);
				}
				else if (arr[i - t] != 0)
				{
					if (arr[i] == 0) arr[i] = arr[i - t] + t / p;
					else arr[i] = min(arr[i], arr[i - t] + t / p);
				}
			}
		}
	}

	if (arr[k] == 0) cout << "-1";
	else cout << arr[k];

	return 0;
}