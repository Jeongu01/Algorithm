#include <iostream>
#include <queue>
#include <string>
using namespace std;

int R, C;
char arr[20][20];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < C; j++)
		{
			arr[i][j] = s.at(j);
		}
	}
	priority_queue<string> pq;
	for (int i = 0; i < R; i++)
	{
		string s;
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] != '#') s += arr[i][j];
			else if (s.length() > 1)
			{
				pq.push(s);
				s = "";
			}
			else s = "";
		}
		if (s.length() > 1) pq.push(s);
		s = "";
	}
	for (int j = 0; j < C; j++)
	{
		string s;
		for (int i = 0; i < R; i++)
		{
			if (arr[i][j] != '#') s += arr[i][j];
			else if (s.length() > 1)
			{
				pq.push(s);
				s = "";
			}
			else s = "";
		}
		if (s.length() > 1) pq.push(s);
		s = "";
	}

	string ans;
	while (!pq.empty())
	{
		ans = pq.top();
		pq.pop();
	}
	cout << ans;
}