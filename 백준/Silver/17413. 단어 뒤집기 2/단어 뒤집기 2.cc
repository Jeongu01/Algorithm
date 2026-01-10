#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
using namespace std;

stack<char> st;

void printWord()
{
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	getline(cin, s);
	bool isTag = false;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		char ch = s.at(i);
		if (isTag == true)
		{
			cout << ch;
			if (ch == '>') isTag = false;
		}
		else if (ch == '<')
		{
			printWord();
			isTag = true;
			cout << "<";
		}
		else if (ch == ' ')
		{
			printWord();
			cout << " ";
		}
		else st.push(ch);
	}
	printWord();
}