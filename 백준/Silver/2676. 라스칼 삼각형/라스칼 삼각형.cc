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
		cout << 1 + (n - m) * m << "\n";
	}
}