#include <iostream>
#include <math.h>
using namespace std;

int arr[2000];
bool visited[2000];

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int K;
	cin >> K;
	int n = pow(2, K) - 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= K; i++)
	{
		int idx = pow(2, K - i);
		for (int j = idx; j <= n; j+=idx)
		{
			if (visited[j] == false)
			{
				cout << arr[j] << " ";
				visited[j] = true;
			}
		}
		cout << "\n";
	}
}