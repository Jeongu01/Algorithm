#include <iostream>
using namespace std;

int N, M;
bool arr[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	cin >> M;
	while (M--)
	{
		int g, num;
		cin >> g >> num;
		if (g == 1)
		{
			for (int i = num; i <= N; i += num)
			{
				arr[i] = !arr[i];
			}
		}
		else
		{
			arr[num] = !arr[num];
			int left = num - 1, right = num + 1;
			while (1 <= left && right <= N)
			{
				if (arr[left] != arr[right]) break;
				arr[left] = !arr[left];
				arr[right] = !arr[right];
				left--;
				right++;
			}
		}
	}
	for (int i = 0; i <= N / 20; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			int idx = (i * 20) + j;
			if (idx > N) break;
			cout << arr[idx] << " ";
		}
		if (i < N / 20) cout << "\n";
	}
}