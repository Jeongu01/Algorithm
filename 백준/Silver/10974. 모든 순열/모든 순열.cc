#include <iostream>
using namespace std;

int N;
int arr[8];
bool isUsed[9];

void func(int depth)
{
	if (depth == N)
	{
		for (int i = 0; i < N; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (isUsed[i] == true)
			continue;
		isUsed[i] = true;
		arr[depth] = i;
		func(depth + 1);
		isUsed[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		arr[0] = i;
		isUsed[i] = true;
		func(1);
		isUsed[i] = false;
	}
}