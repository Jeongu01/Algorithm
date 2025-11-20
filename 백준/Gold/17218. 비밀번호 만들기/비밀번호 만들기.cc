#include <iostream>
#include <algorithm>
using namespace std;

int dp[50][50];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.length(), len2 = s2.length();
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (s1.at(i - 1) == s2.at(j - 1)) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	string ans;
	while (true)
	{
		if (dp[len1][len2] == 0) break;
		else if (dp[len1][len2] == dp[len1 - 1][len2]) len1--;
		else if (dp[len1][len2] == dp[len1][len2 - 1]) len2--;
		else
		{
			ans += s1.at(len1 - 1);
			len1--;
			len2--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}