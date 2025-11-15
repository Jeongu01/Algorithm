#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A, B;
	vector<int> v;
	cin >> A >> B;
	while (A > 0 || B > 0)
	{
		int n = A % 10 + B % 10;
		v.push_back(n);
		A /= 10;
		B /= 10;
	}
	reverse(v.begin(), v.end());
	for (int i : v)
	{
		cout << i;
	}
}