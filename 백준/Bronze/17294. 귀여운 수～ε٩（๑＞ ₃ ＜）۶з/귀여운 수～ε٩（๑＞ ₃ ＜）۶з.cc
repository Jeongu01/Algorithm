#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int len = s.length();
	if (len <= 2)
	{
		cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
		return 0;
	}
	int a = s.at(1) - s.at(0);
	for (int i = 1; i < len; i++)
	{
		if (s.at(i) != s.at(i - 1) + a)
		{
			cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
			return 0;
		}
	}
	cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
}