#include <iostream>
using namespace std;

int main()
{
	string s;
	while (true)
	{
		cin >> s;
		if (s.compare("end") == 0)
			break;
		if (s.compare("animal") == 0)
			cout << "Panthera tigris\n";
		else if (s.compare("tree") == 0)
			cout << "Pinus densiflora\n";
		else if (s.compare("flower") == 0)
			cout << "Forsythia koreana\n";
	}
}