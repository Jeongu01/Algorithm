#include <iostream>
#include <map>
using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	map<string, int> m;
	for (int i = 0; i < N; i++)
	{
		string title;
		cin >> title;
		m[title]++;
	}

	int max = 0;
	string ans;
	for (pair<string, int> e : m)
	{
		if (e.second > max)
		{
			ans = e.first;
			max = e.second;
		}
	}

	cout << ans;
}