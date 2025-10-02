#include <iostream>
using namespace std;

int N, M;
int arr[100'001];
int preSum[100'001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < M; i++)
	{
		int a, b, k;
		cin >> a >> b >> k;
		preSum[a] += k;
		preSum[b + 1] -= k;
	}
	for (int i = 1; i <= N; i++)
	{
		preSum[i] += preSum[i - 1];
		arr[i] = arr[i] + preSum[i];
		cout << arr[i] << " ";
	}
}