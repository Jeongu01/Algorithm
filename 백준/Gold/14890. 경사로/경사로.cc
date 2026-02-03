#include <iostream>
using namespace std;

int N, L;
int arr[100][100];

bool checkRow(int n)
{
	int prev = arr[n][0];
	int len = 1;
	for (int i = 1; i < N; i++)
	{
		if (prev == arr[n][i]) len++;
		else if (prev + 1 == arr[n][i])
		{
			if (len < L)  return false;
			prev = arr[n][i];
			len = 1;
		}
		else if (prev == arr[n][i] + 1)
		{
			prev = arr[n][i];
			for (len = 1; len < L; len++)
			{
				i++;
				if (prev != arr[n][i]) return false;
			}
			len = 0;
		}
		else return false;
	}
	return true;
}

bool checkCol(int n)
{
	int prev = arr[0][n];
	int len = 1;
	for (int i = 1; i < N; i++)
	{
		if (prev == arr[i][n]) len++;
		else if (prev + 1 == arr[i][n])
		{
			if (len < L)  return false;
			prev = arr[i][n];
			len = 1;
		}
		else if (prev == arr[i][n] + 1)
		{
			prev = arr[i][n];
			for (len = 1; len < L; len++)
			{
				i++;
				if (prev != arr[i][n]) return false;
			}
			len = 0;
		}
		else return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans += checkRow(i);
		ans += checkCol(i);
	}
	cout << ans;
}