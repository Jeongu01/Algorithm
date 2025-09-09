#include <iostream>
using namespace std;

int k;
int arr[14], ans[6];

void func(int depth, int n)
{
	if (depth == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = n; i < k; i++)
	{
		ans[depth] = arr[i];
		func(depth + 1, i + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) cin >> arr[i];
		func(0, 0);
		cout << "\n";
	}
}