#include <iostream>
using namespace std;

int main()
{
	int input, hmin = 0x3f3f3f3f, cmin = 0x3f3f3f3f;
	for (int i = 0; i < 3; i++)
	{
		cin >> input;
		hmin = min(hmin, input);
	}
	for (int i = 0; i < 2; i++)
	{
		cin >> input;
		cmin = min(cmin, input);
	}
	cout << hmin + cmin - 50;
}