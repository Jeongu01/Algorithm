#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int k;
		cin >> k;
		map<int, int> m;
		priority_queue<long long> pq, rpq;
		while (k--)
		{
			char cmd;
			long long n;
			cin >> cmd >> n;
			if (cmd == 'I')
			{
				pq.push(n);
				rpq.push(-1 * n);
				m[n]++;
			}
			else if (cmd == 'D' && n == 1)
			{
				while (!pq.empty())
				{
					int x = pq.top();
					pq.pop();
					if (m[x] == 0) continue;
					m[x]--;
					break;
				}
			}
			else if (cmd == 'D' && n == -1)
			{
				while (!rpq.empty())
				{
					int x = rpq.top();
					rpq.pop();
					x *= -1;
					if (m[x] == 0) continue;
					m[x]--;
					break;
				}
			}
		}
		bool isEmpty = true;
		long long maxVal, minVal;
		while (!pq.empty())
		{
			maxVal = pq.top();
			pq.pop();
			if (m[maxVal] == 0) continue;
			isEmpty = false;
			break;
		}
		while (!rpq.empty())
		{
			minVal = rpq.top();
			rpq.pop();
			minVal *= -1;
			if (m[minVal] == 0) continue;
			break;
		}
		if (isEmpty) cout << "EMPTY\n";
		else cout << maxVal << " " << minVal << "\n";
	}
}