#include <iostream>
using namespace std;

int main()
{
	int N, K, M;
	cin >> N >> K >> M;
	int ans = N * K - M;
	ans = max(ans, 0);
	cout << ans;
}