#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int maxV = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		ans += input;
		maxV = max(maxV, input);
	}
	if (n >= 3) ans += maxV * (n - 2);
	cout << ans;
}