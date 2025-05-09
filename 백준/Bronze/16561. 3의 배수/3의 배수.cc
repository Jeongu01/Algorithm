#include <iostream>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	int ans = 0;
	for (int i = 3; i < n; i+=3)
	{
		for (int j = 3; i + j < n; j+=3)
		{
			int k = n - (i + j);
			if (k % 3 == 0) ans++;
		}
	}
	cout << ans;
}