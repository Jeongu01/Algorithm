#include <iostream>
using namespace std;

int main()
{
	int mask = 0x40;
	int x;
	cin >> x;
	int ans = 0, cnt = 0;

	for (int i = 0; i < 7; i++)
	{
		ans |= mask;
		if (ans > x) ans &= ~mask;
		else cnt++;
		mask >>= 1;
	}
	cout << cnt;
}