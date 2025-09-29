#include <iostream>
using namespace std;

int main()
{
	int date, ans = 0; cin >> date;
	for (int i = 0; i < 5; i++)
	{
		int num; cin >> num;
		ans += num % 10 == date;
	}
	cout << ans;
}