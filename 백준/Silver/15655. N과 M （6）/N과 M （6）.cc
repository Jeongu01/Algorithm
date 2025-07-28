#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;
int buffer[8];

void func(int idx, int depth)
{
	buffer[depth - 1] = arr[idx];
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << buffer[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		for (int i = idx + 1; i < N; i++)
		{
			func(i, depth + 1);
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
		int input;
		cin >> input;
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++)
	{
		func(i, 1);
	}
}