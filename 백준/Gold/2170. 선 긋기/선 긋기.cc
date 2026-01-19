#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> lines[1'000'000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		lines[i] = { x, y };
	}
	sort(lines, lines + N);
	int l = lines[0].first;
	int r = lines[0].second;
	if (N == 1)
	{
		cout << r - l;
		return 0;
	}
	long long sum = 0;
	for (int i = 1; i < N; i++)
	{
		if (lines[i].first > r)
		{
			sum += r - l;
			l = lines[i].first;
			r = lines[i].second;
		}
		else if (lines[i].second <= r) continue;
		else r = lines[i].second;
	}
	sum += r - l;
	cout << sum;
}