#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		int input;
		cin >> input;
		sum += max(40, input);
	}
	cout << sum / 5;
}