#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		int t;
		cin >> t;
		map<long long, long long> m;
		long long v = 0, cnt = 0;
		for (int i = 0; i < t; i++)
		{
			long long num;
			cin >> num;
			m[num]++;
			if (m[num] > cnt)
			{
				cnt = m[num];
				v = num;
			}
		}
		if (cnt > t / 2) cout << v << "\n";
		else cout << "SYJKGW\n";
	}
}