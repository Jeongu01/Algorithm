#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int h = 0, a = 0, input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (h < input)
		{
			h = input;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		if (a < input)
		{
			a = input;
		}
	}
	cout << a + h;
}