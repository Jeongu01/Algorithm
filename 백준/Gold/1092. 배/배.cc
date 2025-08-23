#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ans;
vector<int> crane, box;
int cnt[50];

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		crane.push_back(input);
	}
	sort(crane.begin(), crane.end());
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int input;
		cin >> input;
		box.push_back(input);
	}
	sort(box.rbegin(), box.rend());
	if (box[0] > crane[N - 1])
	{
		cout << "-1";
		return 0;
	}
	for (int b = 0; b < M; b++)
	{
		for (int c = 0; c < N; c++)
		{
			if (box[b] <= crane[c] && cnt[c] < ans)
			{
				cnt[c]++;
				break;
			}
			if (c == N - 1 && box[b] <= crane[c] && cnt[c] == ans)
			{
				cnt[c]++;
				ans++;
			}
		}
	}
	cout << ans;
}