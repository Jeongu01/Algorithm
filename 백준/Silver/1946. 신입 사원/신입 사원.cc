#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Score
{
	int a, b;
	Score(int a, int b) : a(a), b(b) {}
	bool operator<(const Score& score) const
	{
		return this->a < score.a;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<Score> v;
		for (int i = 0; i < N; i++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back(Score(a, b));
		}

		sort(v.begin(), v.end());
		int top = N + 1, ans = 0;
		for (Score score : v)
		{
			if (score.b < top)
			{
				ans++;
				top = score.b;
			}
		}
		cout << ans << "\n";
	}
}