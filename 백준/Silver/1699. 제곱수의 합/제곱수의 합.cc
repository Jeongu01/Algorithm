#include <iostream>
using namespace std;

int N;
int arr[100'001];

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	
	for (int i = 1; i <= N; i++) arr[i] = i;
	for (int i = 1; i * i <= N; i++) arr[i * i] = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i / 2; j++)
		{
			arr[i] = min(arr[i], arr[j] + arr[i - j]);
		}
	}

	cout << arr[N];
}