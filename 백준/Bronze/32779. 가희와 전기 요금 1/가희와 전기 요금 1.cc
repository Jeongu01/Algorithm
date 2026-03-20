#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> q;
	while (q--)
	{
		double a, m;
		cin >> a >> m;
		cout << (long long)((a * m * 105.6) / 60000.0 + 1e-9) << "\n";
	}
}