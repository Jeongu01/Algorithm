#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
bool used[8];
vector<int> out;
set<vector<int>> s;

void func(int idx)
{
	if (idx == M)
	{
		if (s.find(out) != s.end()) return;
		for (int i = 0; i < M; i++)
		{
			cout << out[i] << " ";
		}
		cout << "\n";
		s.insert(out);
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (used[i] == false)
		{
			out[idx] = arr[i];
			used[i] = true;
			func(idx + 1);
			used[i] = false;
		}
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
		int input; cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());
	out.resize(M, 0);
	func(0);
}