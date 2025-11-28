#include <iostream>
using namespace std;

int N, ans = -1'000'000'000;
int arr[10];
bool visited[10];
int temp[10];

void func(int depth)
{
	if (depth == N)
	{
		int sum = 0;
		for (int i = 0; i < N - 1; i++)
		{
			sum += abs(temp[i] - temp[i + 1]);
		}
		ans = max(ans, sum);
	}
	for (int i = 0; i < N; i++)
	{
		if (visited[i] == true) continue;
		visited[i] = true;
		temp[depth] = arr[i];
		func(depth + 1);
		visited[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		visited[i] = true;
		temp[0] = arr[i];
		func(1);
		visited[i] = false;
	}
	cout << ans;
}