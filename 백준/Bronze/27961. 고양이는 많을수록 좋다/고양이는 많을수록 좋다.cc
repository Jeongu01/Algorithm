#include <iostream>
using namespace std;

int main()
{
	long long N;
	cin >> N;
	long long cnt = 1, cat = 1;
	if (N == 0) cout << 0;
	else
	{
		while (cat < N)
		{
			cnt++;
			cat *= 2;
		}
		cout << cnt;
	}
}