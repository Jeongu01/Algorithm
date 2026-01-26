#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

double arr[26];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	string cmd;
	cin >> cmd;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int len = cmd.length();
	stack<double> st;
	for (int i = 0; i < len; i++)
	{
		char c = cmd.at(i);
		if ('A' <= c && c <= 'Z')
		{
			st.push(arr[c - 'A']);
		}
		else
		{
			double op2 = st.top(); st.pop();
			double op1 = st.top(); st.pop();
			switch (c)
			{
			case '+':
				st.push(op1 + op2);
				break;
			case '-':
				st.push(op1 - op2);
				break;
			case '*':
				st.push(op1 * op2);
				break;
			case '/':
				st.push(op1 / op2);
				break;
			}
		}
	}
	printf("%.2f", st.top());
}