#include <iostream>
using namespace std;

int N;
int arr[10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int left;
		cin >> left;
		int cnt = 0, idx = 0;
		while (true)
		{
			if (cnt == left && arr[idx] == 0) break;
			if (arr[idx] == 0)
			{
				cnt++;
			}
			idx++;
		}
		arr[idx] = i;
	}
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
}