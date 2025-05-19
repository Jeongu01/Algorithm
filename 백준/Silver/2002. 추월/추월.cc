#include <iostream>
#include <unordered_map>
using namespace std;

string arr[1001];
unordered_map<string, bool> m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string car;
		cin >> car;
		arr[i] = car;
		m[car] = false;
	}

	int in = 0, out = 0;
	for (int i = 0; i < N; i++)
	{
		string car;
		cin >> car;
		m[car] = true;
		if (arr[in].compare(car) == 0)
		{
			while (m[arr[in]]) 
			{
				in++;
			}
		}
		else
		{
			out++;
		}
	}
	cout << out;
}