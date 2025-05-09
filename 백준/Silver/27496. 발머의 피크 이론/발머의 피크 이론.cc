#include <iostream>
#include <queue>
using namespace std;

int N, L, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;
	queue<int> q;
	for (int i = 0; i < L; i++)
	{
		q.push(0);
	}

	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		sum += a;
		q.push(a);
		int c = q.front();
		q.pop();
		sum -= c;
		if (129 <= sum && sum <= 138) ans++;
	}
	cout << ans;
}