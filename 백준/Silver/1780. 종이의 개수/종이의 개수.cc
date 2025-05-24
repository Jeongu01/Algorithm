#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
int ans[3];

int func(int r, int c, int N)
{
	if (N == 1) return arr[r][c];
	int nextr = r, nextN = N / 3;
	int cnt[4] = { 0, };
	for (int i = 0; i < 3; i++)
	{
		int nextc = c;
		for (int j = 0; j < 3; j++)
		{
			cnt[func(nextr, nextc, nextN) + 1]++;
			nextc += nextN;
		}
		nextr += nextN;
	}

	bool isSame = true;
	int cntNum = 0, ret;
	for (int i = 0; i < 4; i++)
	{
		if (cnt[i] != 0)
		{
			ret = i - 1;
			cntNum++;
		}
	}
	if (cntNum != 1 || cnt[3] != 0)
	{
		for (int i = 0; i < 3; i++)
		{
			ans[i] += cnt[i];
		}
		return 2;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		vector<int> row;
		for (int j = 0; j < N; j++)
		{
			int input;
			cin >> input;
			row.push_back(input);
		}
		arr.push_back(row);
	}

	int ret = func(0, 0, N);
	if (ret != 2) ans[ret + 1]++;
	for (int a : ans) cout << a << "\n";
}