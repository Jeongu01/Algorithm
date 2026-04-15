#include <iostream>
#include <algorithm>
using namespace std;

string s, t;
bool ans;

void func(string str)
{
	if (ans == true) return;
	if (str.length() == s.length())
	{
		if (str == s)
			ans = true;
		return;
	}
	if (str.back() == 'A')
	{
		string nxt = str;
		nxt.pop_back();
		func(nxt);
	}

	if (str.front() == 'B')
	{
		string nxt = str;
		reverse(nxt.begin(), nxt.end());
		nxt.pop_back();
		func(nxt);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> t;
	func(t);
	if (ans) cout << 1;
	else cout << 0;
}