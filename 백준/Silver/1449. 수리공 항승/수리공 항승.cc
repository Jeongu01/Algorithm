#include <iostream>
using namespace std;

int N, L;
bool arr[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		int input; cin >> input;
		arr[input] = true;
	}
	int ans = 0, i = 0;
	while (i <= 1000)
	{
		if (arr[i] == true)
		{
			i += L;
			ans++;
		}
		else i++;
	}
	cout << ans;
}