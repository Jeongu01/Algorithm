#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input;
	cin >> input;
	int now = 0, cnt = 0, ans = 0;
	char pre = input.at(0);
	now++;
	cnt++;
	for (int i = 1; i < input.length(); i++)
	{
		char c = input.at(i);
		if (c == '(')
		{
			now++;
			cnt++;
		}
		else if (c == ')')
		{
			now--;
			if (pre == '(')
			{
				cnt--;
				ans += now;
			}
		}
		pre = c;
	}
	ans += cnt;
	cout << ans;
}