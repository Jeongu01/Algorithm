#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	int trgw, m;
	int sum = 0;
	for (int i = 0; i < 13; i++)
	{
		int w = i % 2 == 0 ? 1 : 3;
		char c = s.at(i);
		if (c == '*')
		{
			trgw = w;
			continue;
		}
		int a = c - '0';
		sum += a * w;
	}

	for (int i = 0; i < 10; i++)
	{
		if ((sum + i * trgw) % 10 == 0)
		{
			cout << i;
			break;
		}
	}
}