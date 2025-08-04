#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, input;
	cin >> N;
	vector<int> A, B;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		A.push_back(input);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		B.push_back(input);
	}

	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end());

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans += A[i] * B[i];
	}
	cout << ans;
}