#include <iostream>

using namespace std;

int arr[10000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int index = 1;
	for (int i = 1; i < 1000 && index <= 1000; i++)
	{
		for (int j = 0; j < i; j++)
		{
			arr[index] = arr[index - 1] + i;
			index++;
		}
	}
	int s, e;
	cin >> s >> e;
	cout << arr[e] - arr[s - 1];
}