#include <iostream>
using namespace std;

string arr[5] =
{
	{"@   @"},
	{"@  @"},
	{"@@@"},
	{"@  @"},
	{"@   @"}
};

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int len = arr[i].length();
			for (int k = 0; k < len; k++)
			{
				for (int l = 0; l < N; l++)
				{
					cout << arr[i].at(k);
				}
			}
			cout << "\n";
		}
	}
}