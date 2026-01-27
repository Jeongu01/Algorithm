#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[26];
bool isUsed[26];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		fill(isUsed, isUsed + 26, false);
		string s;
		cin >> s;
		int len = s.length();
		for (int j = 0; j < len; j++)
		{
			char c = s.at(j);
			if (isUsed[c - 'A'] == true) continue;
			isUsed[c - 'A'] = true;
			int v = 0;
			for (int k = 0; k < len; k++)
			{
				v *= 10;
				if (s.at(k) == c) v++;
			}
			arr[c - 'A'] -= v;
		}
	}
	sort(arr, arr + 26);
	int ans = 0, w = -9;
	for (int i = 0; i < 10; i++)
	{
		ans += arr[i] * w;
		w++;
	}
	cout << ans;
}