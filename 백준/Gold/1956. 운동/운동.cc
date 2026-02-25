#include <iostream>
using namespace std;

int V, E;
int arr[401][401];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			arr[i][j] = 0x3f3f3f3f;
		}
		arr[i][i] = 0;
	}
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
	}
	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++)
			for (int j = 1; j <= V; j++)
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];

	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (i == j 
				|| arr[i][j] == 0x3f3f3f3f 
				|| arr[j][i] == 0x3f3f3f3f)
				continue;
			if (ans > arr[i][j] + arr[j][i])
				ans = arr[i][j] + arr[j][i];
		}
	}
	if (ans == 0x3f3f3f3f)
		ans = -1;
	cout << ans;
}