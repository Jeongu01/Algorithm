#include <iostream>
#include <queue>
#define POS		pair<int, int>
#define x		first
#define y		second
using namespace std;

int n;
POS home;
POS conv[101];
bool visited[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		cin >> home.x >> home.y;
		for (int i = 0; i <= n; i++)
		{
			cin >> conv[i].x >> conv[i].y;
			visited[i] = false;
		}
		queue<POS> q;
		q.push(home);
		while (!q.empty())
		{
			POS curP = q.front(); q.pop();
			if (curP == conv[n]) break;
			for (int i = 0; i <= n; i++)
			{
				if (visited[i] == true) continue;
				POS nxtP = conv[i];
				if (abs(curP.x - nxtP.x) + abs(curP.y - nxtP.y) > 1000) continue;
				visited[i] = true;
				q.push(conv[i]);
			}
		}
		string ans = visited[n] ? "happy\n" : "sad\n";
		cout << ans;
	}
}