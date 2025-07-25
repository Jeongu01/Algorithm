#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	if (!s.compare("NLCS"))
	{
		cout << "North London Collegiate School";
	}
	else if (!s.compare("BHA"))
	{
		cout << "Branksome Hall Asia";
	}
	else if (!s.compare("KIS"))
	{
		cout << "Korea International School";
	}
	else
	{
		cout << "St. Johnsbury Academy";
	}
}