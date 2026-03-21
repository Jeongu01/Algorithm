#include <iostream>
using namespace std;

long long calc(long long n, int m)
{
	long long ret = 0, i = m;
	while (n / i > 0)
	{
		ret += n / i;
		i *= m;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n, m;
	cin >> n >> m;
	long long cnt2 = 0, cnt5 = 0;
	cnt2 = calc(n, 2) - calc(m, 2) - calc(n - m, 2);
	cnt5 = calc(n, 5) - calc(m, 5) - calc(n - m, 5);
	cout << min(cnt2, cnt5);
}