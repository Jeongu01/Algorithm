#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	long long ans = 0;
	cin >> N;
	stack<pair<int, int>> s;
	while (N--)
	{
		int H;
		cin >> H;
		while (!s.empty())
		{
			auto& t = s.top();
			if (t.first >= H) break;
			ans += t.second;
			s.pop();
		}
		if (!s.empty())
		{
			auto& t = s.top();
			if (t.first == H)
			{
				ans += t.second;
				if (s.size() > 1) ans++;
				t.second++;
			}
			else if (t.first > H)
			{
				ans++;
				s.push({ H, 1 });
			}
		}
		else
		{
			s.push({ H, 1 });
		}
	}
	cout << ans;
}