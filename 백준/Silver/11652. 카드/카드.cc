#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	map<long long, int> m;
	while (N--)
	{
		long long int input;
		cin >> input;
		m[input]++;
	}
	long long ansV = INT64_MAX, ansCnt = 0;
	for (auto &it : m)
	{
		if (ansCnt < it.second || (ansCnt == it.second && ansV > it.first))
		{
			ansV = it.first;
			ansCnt = it.second;
		}
	}
	cout << ansV;
}