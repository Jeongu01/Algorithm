#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, k;
int row = 3, col = 3;
int A[101][101];
int cnt[101];

void R()
{
	int newCol = 0;
	for (int i = 1; i <= row; i++)
	{
		fill(cnt, cnt + 101, 0);
		for (int j = 1; j <= col; j++)
		{
			if (A[i][j] == 0) continue;
			cnt[A[i][j]]++;
		}
		vector<pair<int, int>> v; // { 횟수, 수 }
		for (int j = 1; j <= 100; j++)
		{
			if (cnt[j] == 0) continue;
			v.push_back({ cnt[j], j });
		}
		sort(v.begin(), v.end());
		int size = v.size();
		int idx = 1;
		for (int j = 0; j < size; j++)
		{
			if (idx > 100) break;
			A[i][idx++] = v[j].second;
			A[i][idx++] = v[j].first;
		}
		for (int j = idx; j <= 100; j++)
		{
			A[i][j] = 0;
		}
		newCol = max(newCol, idx - 1);
	}
	col = newCol;
}

void C()
{
	int newRow = 0;
	for (int i = 1; i <= col; i++)
	{
		fill(cnt, cnt + 101, 0);
		for (int j = 1; j <= row; j++)
		{
			if (A[j][i] == 0) continue;
			cnt[A[j][i]]++;
		}
		vector<pair<int, int>> v; // { 횟수, 수 }
		for (int j = 1; j <= 100; j++)
		{
			if (cnt[j] == 0) continue;
			v.push_back({ cnt[j], j });
		}
		sort(v.begin(), v.end());
		int size = v.size();
		int idx = 1;
		for (int j = 0; j < size; j++)
		{
			if (idx > 100) break;
			A[idx++][i] = v[j].second;
			A[idx++][i] = v[j].first;
		}
		for (int j = idx; j <= 100; j++)
		{
			A[j][i] = 0;
		}
		newRow = max(newRow, idx - 1);
	}
	row = newRow;
}

int main(void)
{
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 0; i <= 100; i++)
	{
		if (r <= row && c <= col && A[r][c] == k)
		{
			cout << i;
			return 0;
		}
		if (row >= col) R();
		else C();
	}
	cout << -1;
}