#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> A;
	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		A.push_back(abs(S - input));
	}
	sort(A.begin(), A.end());

	int ans = A[0];
	for (int i = 1; i < N; i++)
	{
		ans = gcd(A[i], ans);
	}
	cout << ans;
}