#include <iostream>
using namespace std;

int main()
{
	int input;
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> input;
		sum1 += input;
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> input;
		sum2 += input;
	}
	cout << max(sum1, sum2);
}