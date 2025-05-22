#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, M;
int v[8], ans[8];
set<int> s;

void func(int idx, int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i < N; i++)
	{
		ans[depth] = v[i];
		func(i, depth + 1);
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
		int input;
		cin >> input;
		s.insert(input);
	}

	N = s.size();
	int i = 0;
	for (int a : s)
	{
		v[i++] = a;
	}

	func(0, 0);
	
	return 0;
}