#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	set<int> t;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		t.insert(input);
	}
	int ans = 0;
	while (true)
	{
		ans++;
		if (t.find(ans) == t.end())
		{
			cout << ans;
			return 0;
		}
	}
}