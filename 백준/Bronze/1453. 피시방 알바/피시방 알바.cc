#include <iostream>
using namespace std;

bool arr[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		if (arr[t] == true) ans++;
		else arr[t] = true;
	}
	cout << ans;
}