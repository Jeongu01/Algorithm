#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, ans;
	cin >> N;
	for (int i = 0; i < 5; i++)
	{
		int temp = (N - 3 * i) % 5;
		if (temp == 0)
		{
			ans = (N - 3 * i) / 5 + i;
			break;
		}
		if (temp < 0)
		{
			ans = -1;
			break;
		}
	}
	cout << ans;
}