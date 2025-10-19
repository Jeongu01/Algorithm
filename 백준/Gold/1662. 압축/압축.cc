#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string S;
	cin >> S;
	int len = S.length();
	stack<pair<int, bool>> st;
	for (int i = 0; i < len; i++)
	{
		char c = S.at(i);
		if (c == '(')
		{
			st.push({ -1, false });
		}
		else if (c == ')')
		{
			int q = 0;
			while (!st.empty())
			{
				auto cur = st.top();
				st.pop();
				if (cur.first == -1) break;
				if (cur.second == true) q += cur.first;
				else q++;
			}
			int k = st.top().first;
			st.pop();
			st.push({ k * q, true });
		}
		else
		{
			st.push({ c - '0', false });
		}
	}
	int ans = 0;
	while (!st.empty())
	{
		auto cur = st.top();
		st.pop();
		if (cur.second == true) ans += cur.first;
		else ans++;
	}
	cout << ans;
}