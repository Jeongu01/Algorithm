#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		long long n, m;
		cin >> n >> m;
		long long day = 0;
		while (n > 0)
		{
			day++;
			n /= 2;
		}
		day += m;
		cout << day << "\n";
	}
}