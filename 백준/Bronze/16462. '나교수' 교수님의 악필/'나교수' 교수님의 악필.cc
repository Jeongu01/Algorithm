#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		if (input == 100)
		{
			sum += 100;
			continue;
		}
		if (input % 10 == 6) input += 3;
		if (input % 10 == 0) input += 9;
		if (input >= 10 && input / 10 == 6) input += 30;
		sum += input;
	}
	double avg = (double)sum / N;
	int ans = (int)avg;
	if (avg - (int)avg >= 0.5) ans++;
	cout << ans;
}