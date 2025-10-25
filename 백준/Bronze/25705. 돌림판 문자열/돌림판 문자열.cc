#include <iostream>
using namespace std;

bool existed[26];

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	string T;
	cin >> T;
	for (int i = 0; i < N; i++)
	{
		char c = T.at(i);
		existed[c - 'a'] = true;
	}
	int M, ans = 0, idx = N - 1;
	cin >> M;
	string S;
	cin >> S;
	for (int i = 0; i < M; i++)
	{
		char c = S.at(i);
		if (existed[c - 'a'] == false)
		{
			cout << "-1";
			return 0;
		}
		do
		{
			ans++;
			idx = (idx + 1) % N;
		} while (T.at(idx) != c);
	}
	cout << ans;
}