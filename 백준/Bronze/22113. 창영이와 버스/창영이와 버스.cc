#include <iostream>
using namespace std;

int N, M;
int arr[101][101];
int cmd[100];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> cmd[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i < M; i++)
	{
		ans += arr[cmd[i - 1]][cmd[i]];
	}
	cout << ans;
}