#include <iostream>
using namespace std;

string input;

int check(int s, int e, int ans)

{
	int ret = 2;
	while (s < e)
	{
		if (ans == 2 || ret != 2) break;
		do
		{
			if (input.at(s) == input.at(e)) break;
			if (input.at(s + 1) == input.at(e))
			{
				ret = check(s + 1, e, ans + 1);
				if (ret != 2)
				{
					ans = ret;
					break;
				}
			}
			if (input.at(s) == input.at(e - 1))
			{
				ret = check(s, e - 1, ans + 1);
				if (ret != 2)
				{
					ans = ret;
					break;
				}
			}
			ans = 2;
		} while (false);
		s++;
		e--;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	while (N--)
	{
		cin >> input;
		int s = 0, e = input.length() - 1;
		cout << check(s, e, 0) << "\n";
	}
}