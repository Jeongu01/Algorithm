#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		string input; cin >> input;
		int K; cin >> K;
		vector<int> alpha['z' - 'a' + 1];
		int len = input.length();
		for (int i = 0; i < len; i++)
		{
			alpha[input.at(i) - 'a'].push_back(i);
		}
		int minA = 0x3f3f3f3f, maxA = -1;
		for (int i = 0; i <= 'z' - 'a'; i++)
		{
			int size = alpha[i].size();
			if (size >= K)
			{
				for (int j = 0; j <= size - K; j++)
				{
					minA = min(minA, alpha[i][j + K - 1] - alpha[i][j] + 1);
					maxA = max(maxA, alpha[i][j + K - 1] - alpha[i][j] + 1);
				}
			}
		}
		if (maxA == -1) cout << "-1\n";
		else cout << minA << " " << maxA << "\n";
	}
}