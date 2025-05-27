#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int js, ij;
	cin >> js >> ij;
	if (js == 0)
	{
		if (ij == 0) cout << "=";
		else if (ij == 5) cout << "<";
		else cout << ">";
	}
	else if (js == 2)
	{
		if (ij == 2) cout << "=";
		else if (ij == 0) cout << "<";
		else cout << ">";
	}
	else if (js == 5)
	{
		if (ij == 5) cout << "=";
		else if (ij == 2) cout << "<";
		else cout << ">";
	}
	else
	{
		if (ij == 0 || ij == 2 || ij == 5) cout << "<";
		else cout << "=";
	}
}