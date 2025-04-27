#include <iostream>
using namespace std;

int arr[500000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	string input;
	cin >> input;

	char now = input.at(0);
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		if (input.at(i) == now) arr[index]++;
		else
		{
			now = input.at(i);
			index++;
			arr[index]++;
		}
	}

	int ans = INT16_MAX;
	int sum1 = 0, sum2 = 0;
	for (int i = 1; i <= index; i++)
	{
		if (i % 2 == 0) sum1 += arr[i];
		else sum2 += arr[i];
	}
	ans = min(ans, sum1);
	ans = min(ans, sum2);

	sum1 = 0, sum2 = 0;
	for (int i = index - 1; i >= 0; i--)
	{
		if (i % 2 == 0) sum1 += arr[i];
		else sum2 += arr[i];
	}
	ans = min(ans, sum1);
	ans = min(ans, sum2);

	cout << ans;

	return 0;
}