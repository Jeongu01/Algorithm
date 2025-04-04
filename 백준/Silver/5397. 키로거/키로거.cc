#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string s;
		cin >> s;
		int L = s.length();
		list<char> answer;
		list<char>::iterator it = answer.begin();

		for (int j = 0; j < L; j++)
		{
			char input = s.at(j);
			switch (input)
			{
			case '<':
				if (it != answer.begin())
					--it;
				break;
			case '>':
				if (it != answer.end())
					++it;
				break;
			case '-':
				if (it != answer.begin())
				{
					--it;
					it = answer.erase(it);
				}
				break;
			default:
				it = answer.insert(it, input);
				++it;
				break;
			}
		}

		for (it = answer.begin(); it != answer.end(); ++it)
		{
			cout << *it;
		}
		cout << '\n';
	}
	


	return 0;
}