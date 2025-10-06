#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N, M;
int arr[8];
vector<int> ans;
set<vector<int>> s;

void func(int depth, int idx)
{
	if (depth == M)
	{
		if (s.find(ans) != s.end()) return;
		for (int i : ans)
		{
			cout << i << " ";
		}
		cout << "\n";
		s.insert(ans);
		return;
	}
	for (int i = idx; i < N; i++)
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

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	ans.resize(M, 0);
	sort(arr, arr + N);
	func(0, 0);
}