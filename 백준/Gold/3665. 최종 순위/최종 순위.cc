#include <iostream>
#include <vector>
#include <string>
using namespace std;

int arr[501], deg[501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int TC, n, m, input, a, b;
	cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			deg[input] = j;
			arr[input] = j;
		}
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> a >> b;
			int ao = arr[a], bo = arr[b];
			if (ao < bo)
			{
				deg[a]++;
				deg[b]--;
			}
			else
			{
				deg[a]--;
				deg[b]++;
			}
		}
		string ans;
		for (int j = 0; j < n; j++)
		{
			bool question = false, consistent = false;
			int target = -1;
			for (int k = 1; k <= n; k++)
			{
				if (deg[k] == j)
				{
					if (target == -1) target = k;
					else question = true;
				}
			}
			consistent = target == -1;
			if (question)
			{
				ans = "?";
				break;
			}
			else if (consistent)
			{
				ans = "IMPOSSIBLE";
				break;
			}
			else ans += to_string(target) + " ";
		}
		cout << ans << "\n";
	}
}