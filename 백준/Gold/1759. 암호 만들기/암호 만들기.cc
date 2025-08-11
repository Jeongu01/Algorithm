#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C, acnt, bcnt;
char ans[16];
vector<char> v;

void func(int idx, int len)
{
	ans[len] = v[idx];
	bool check = false;
	switch (v[idx])
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		check = true;
	}
	if (check) acnt++;
	else bcnt++;

	if (len == L)
	{
		if (acnt >= 1 && bcnt >= 2)
		{
			for (int i = 1; i <= L; i++)
			{
				cout << ans[i];
			}
			cout << "\n";
		}
		if (check) acnt--;
		else bcnt--;
		return;
	}
	for (int i = idx + 1; i < C; i++)
	{
		func(i, len + 1);
	}
	if (check) acnt--;
	else bcnt--;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		char input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i <= C - L; i++)
	{
		func(i, 1);
	}
}