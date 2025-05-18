#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int len = 1'299'710;
bool arr[len];
vector<int> primes;
int T;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	primes.push_back(1);
	for (int i = 2; i < len; i++)
	{
		if (!arr[i])
		{
			primes.push_back(i);
			for (int j = i + i; j < len; j += i)
			{
				arr[j] = true;
			}
		}
	}

	sort(primes.begin(), primes.end());

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int k;
		cin >> k;
		if (!arr[k]) cout << "0\n";
		else
		{
			int s = 0;
			int e = primes.size() - 1;
			while (e - s > 1)
			{
				int mid = (s + e) / 2;
				if (primes[mid] > k)
				{
					e = mid;
				}
				else
				{
					s = mid;
				}
			}
			cout << primes[e] - primes[s] << "\n";
		}
	}

	return 0;
}