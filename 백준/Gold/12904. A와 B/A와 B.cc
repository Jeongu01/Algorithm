#include <iostream>
using namespace std;

string S, T;
int Slen;
bool ans;

void func(string st, int len, bool rev)
{
	if (len == Slen) {
		if (!rev)
		{
			for (int i = 0; i < Slen; i++)
			{
				if (S.at(i) != st.at(i)) return;
			}
			ans = true;
		}
		else
		{
			for (int i = 0; i < Slen; i++)
			{
				if (S.at(i) != st.at(Slen - 1 - i)) return;
			}
			ans = true;
		}
		return;
	}
	if (!rev)
	{
		if (st.at(len - 1) == 'A') func(st.substr(0, len - 1), len - 1, rev);
		if (st.at(len - 1) == 'B') func(st.substr(0, len - 1), len - 1, !rev);
	}
	else
	{
		if (st.at(0) == 'A') func(st.substr(1, len - 1), len - 1, rev);
		if (st.at(0) == 'B') func(st.substr(1, len - 1), len - 1, !rev);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> S >> T;
	Slen = S.length();
	func(T, T.length(), false);
	int a = ans ? 1 : 0;
	cout << a;
}