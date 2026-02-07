#include<iostream>
#include <stack>
#include <list>
#include <iterator>
using namespace std;

string s;

string func(int idx, int len)
{
	list<string> buf;
	for (int i = idx; i < idx + len; i++)
	{
		if (s.at(i) == '(')
		{
			int bCnt = 1, bStart = i + 1;
			while (bCnt != 0)
			{
				i++;
				char c = s.at(i);
				if (c == '(') bCnt++;
				else if (c == ')') bCnt--;
			}
			int bLen = i - bStart;
			string res = func(bStart, bLen);
			buf.push_back(res);
		}
		else
		{
			buf.push_back(string(1, s.at(i)));
		}
	}

	list<string>::iterator it = buf.begin();
	for (; it != buf.end(); ++it)
	{
		string st = *it;
		if (st.compare("*") == 0 || st.compare("/") == 0)
		{
			string merged = *prev(it) + *next(it) + *it;
			auto after = buf.erase(prev(it), next(next(it)));
			auto inserted = buf.insert(after, merged);
			it = inserted;
		}
	}

	it = buf.begin();
	for (; it != buf.end(); ++it)
	{
		string st = *it;
		if (st.compare("+") == 0 || st.compare("-") == 0)
		{
			string merged = *prev(it) + *next(it) + *it;
			auto after = buf.erase(prev(it), next(next(it)));
			auto inserted = buf.insert(after, merged);
			it = inserted;
		}
	}

	string ret = "";
	for (auto e : buf)
	{
		ret += e;
	}
	return ret;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	int len = s.length();
	string ans = func(0, len);
	cout << ans;
}