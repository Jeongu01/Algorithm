#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	deque<char> dq;
	stack<bool> st;
	for (int i = 0; i < N; i++)
	{
		int cmd;
		cin >> cmd;
		char c;
		switch (cmd)
		{
		case 1:
			cin >> c;
			dq.push_back(c);
			st.push(true);
			break;
		case 2:
			cin >> c;
			dq.push_front(c);
			st.push(false);
			break;
		case 3:
			if (!dq.empty())
			{
				bool flag = st.top();
				st.pop();
				if (flag) dq.pop_back();
				else dq.pop_front();
			}
			break;
		}
	}
	if (dq.empty()) cout << "0";
	else
	{
		while (!dq.empty())
		{
			cout << dq.front();
			dq.pop_front();
		}
	}
}