#include <iostream>
using namespace std;

int cost[1'000'001];

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	for (int i = 2; i <= 1'000'000; i++)
	{
		int sum = 0;
		for (int j = i; j <= 1'000'000; j++)
		{
			sum += j;
			if (sum > 1'000'000) break;
			cost[sum]++;
		}
	}

	while (true)
	{
		int N;
		cin >> N;
		if (N == 0) break;
		cout << cost[N] << "\n";
	}
}