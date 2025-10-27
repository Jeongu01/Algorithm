#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	long long pre, cur, ans = 0;
	cin >> pre;
	for (int i = 1; i < N; i++)
	{
		cin >> cur;
		if (pre > cur)
		{
			while (pre > cur)
			{
				cur <<= 1;
				ans++;
			}
		}
		pre = cur;
	}
	cout << ans;
}