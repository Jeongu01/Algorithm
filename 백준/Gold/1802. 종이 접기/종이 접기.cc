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
		string s;
		cin >> s;
		int len = s.length();
		bool flag = true;
		while (len > 1 && flag == true)
		{
			int s1 = 0, s2 = len - 1;
			len /= 2;
			for (int i = 0; i < len; i++)
			{
				if (s.at(s1 + i) == s.at(s2 - i))
				{
					flag = false;
					break;
				}
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}