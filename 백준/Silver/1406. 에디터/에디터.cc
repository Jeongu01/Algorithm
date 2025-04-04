#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;

	list<char> answer;

	int length = input.length();
	for (int i = 0; i < length; ++i)
	{
		answer.push_back(input[i]);
	}

	int N;
	cin >> N;

	list<char>::iterator it = answer.end();
	for (int i = 0; i < N; i++)
	{
		char command;
		cin >> command;
		switch (command)
		{
		case 'L':
			if (it != answer.begin())
				--it;
			break;
		case 'D':
			if (it != answer.end())
				++it;
			break;
		case 'B':
			if (it != answer.begin())
			{
				it--;
				it = answer.erase(it);
			}
			break;
		case 'P':
			char c;
			cin >> c;
			answer.insert(it, c);
			break;
		}
	}

	it = answer.begin();
	for (list<char>::iterator i = it; i != answer.end(); ++i)
	{
		cout << *i;
	}

	return 0;
}