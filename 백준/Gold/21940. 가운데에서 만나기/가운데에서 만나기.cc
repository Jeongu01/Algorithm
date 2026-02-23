#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
int arr[201][201];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i != j) arr[i][j] = 0x3f3f3f3f;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int A, B, T;
		cin >> A >> B >> T;
		arr[A][B] = T;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				if (arr[i][j] <= arr[i][k] + arr[k][j])
					continue;
				arr[i][j] = arr[i][k] + arr[k][j];
			}
	cin >> K;
	vector<int> v;
	for (int i = 0; i < K; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	vector<int> ans;
	int ansT = 0x3f3f3f3f;
	for (int i = 1; i <= N; i++)
	{
		int maxT = 0;
		for (int e : v)
		{
			if (arr[e][i] + arr[i][e] > maxT)
			{
				maxT = arr[e][i] + arr[i][e];
			}
		}
		if (maxT == ansT)
			ans.push_back(i);
		else if (maxT < ansT)
		{
			ans.clear();
			ans.push_back(i);
			ansT = maxT;
		}
	}

	for (int a : ans)
	{
		cout << a << " ";
	}
}