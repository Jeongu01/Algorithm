#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		input = -input;
		auto it = lower_bound(v.begin(), v.end(), input);
		if (it == v.end()) v.push_back(input);
		else *it = input;
	}
	cout << v.size();
}