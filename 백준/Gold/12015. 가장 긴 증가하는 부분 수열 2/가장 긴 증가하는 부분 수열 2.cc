#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> A;
vector<int> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		A.push_back(input);
	}
	v.push_back(A[0]);
	for (int i = 1; i < N; i++)
	{
		auto it = lower_bound(v.begin(), v.end(), A[i]);
		if (it == v.end()) v.push_back(A[i]);
		else *it = A[i];
	}
	cout << v.size();
}