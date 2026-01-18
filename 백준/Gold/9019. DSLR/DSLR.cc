#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int D(int n)
{
	return (n + n) % 10000;
}

int S(int n)
{
	if (n == 0) return 9999;
	return n - 1;
}

int L(int n)
{
	n = n * 10;
	int d1 = n / 10000;
	return (n % 10000) + d1;
}

int R(int n)
{
	int d4 = n % 10;
	return (n / 10) + (d4 * 1000);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int A, B;
		cin >> A >> B;
		int pre[10000];
		char cmd[10000];
		fill(pre, pre + 10000, -1);
		queue<int> q;
		q.push(A);
		pre[A] = 0x3f3f3f3f;
		cmd[A] = 'A';
		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			if (cur == B) break;
			int nxt;
			nxt = D(cur);
			if (pre[nxt] == -1)
			{
				pre[nxt] = cur;
				cmd[nxt] = 'D';
				q.push(nxt);
			}
			nxt = S(cur);
			if (pre[nxt] == -1)
			{
				pre[nxt] = cur;
				cmd[nxt] = 'S';
				q.push(nxt);
			}
			nxt = L(cur);
			if (pre[nxt] == -1)
			{
				pre[nxt] = cur;
				cmd[nxt] = 'L';
				q.push(nxt);
			}
			nxt = R(cur);
			if (pre[nxt] == -1)
			{
				pre[nxt] = cur;
				cmd[nxt] = 'R';
				q.push(nxt);
			}
		}
		
		vector<char> ans;
		int prev = B;
		while (prev != A)
		{
			ans.push_back(cmd[prev]);
			prev = pre[prev];
		}
		reverse(ans.begin(), ans.end());
		for (char c : ans)
		{
			cout << c;
		}
		cout << "\n";
	}
}