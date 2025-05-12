#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[5'000'001];
vector<int> primes;
int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n = sqrt(5000001);
	for (int i = 0; i < 5'000'000; i++)
	{
		arr[i] = i;
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == i)
		{
			primes.push_back(i);
			for (int j = i + i; j <= 5'000'000; j += i)
			{
				arr[j] = i;
			}
		}
	}

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;

		vector<int> v;
		while (k > 1)
		{
			v.push_back(arr[k]);
			k /= arr[k];
		}
		sort(v.begin(), v.end());
		for (auto a : v)
		{
			cout << a << " ";
		}
		cout << "\n";
	}

}