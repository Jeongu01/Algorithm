#include <iostream>
#include <stack>
using namespace std;

stack<int> st;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, ans = 0;
	cin >> n;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		while (!st.empty() && st.top() > y)
		{
			st.pop();
		}
		if ((st.empty() || st.top() < y) && y != 0)
		{
			st.push(y);
			ans++;
		}
	}
	cout << ans;
}