#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Line
{
	int a, b;
	Line(int a, int b) : a(a), b(b) {}
	bool operator<(const Line l) const
	{
		return this->a < l.a;
	}
};

vector<Line> arr;
int dp[100];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		arr.push_back(Line(a, b));
		dp[i] = 1;
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i].a > arr[j].a && arr[i].b > arr[j].b)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans = max(ans, dp[i]);
	}

	cout << N - ans;
}