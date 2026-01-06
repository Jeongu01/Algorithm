#include <iostream>
using namespace std;

int V, P;
long long L, ans;
long long arr[20], pos[20], anspos[20];

void func(int depth, int start)
{
	if (depth == P)
	{
		long long sum = 0;
		for (int i = 0; i < V; i++)
		{
			long long m = 0x3f3f3f3f3f3f3f3f;
			for (int j = 0; j < P; j++)
			{
				long long dist = abs(arr[i] - arr[pos[j]]);
				m = min(m, min(dist, abs(L - dist)));
			}
			sum += m;
			if (sum >= ans) return;
		}
		ans = sum;
		for (int i = 0; i < P; i++)
		{
			anspos[i] = pos[i];
		}
		return;
	}
	for (int i = start; i < V; i++)
	{
		pos[depth] = i;
		func(depth + 1, i + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ans = 0x3f3f3f3f3f3f3f3f;
	cin >> V >> P >> L;
	for (int i = 0; i < V; i++)
	{
		cin >> arr[i];
	}
	func(0, 0);
	cout << ans << "\n";
	for (int i = 0; i < P; i++)
	{
		cout << arr[anspos[i]] << " ";
	}
}