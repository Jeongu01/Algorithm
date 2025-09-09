#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		string p; cin >> p;
		int n; cin >> n;
		deque<int> d;
		bool rev = false, errFlag = false;

		string arr; cin >> arr;
		int len = arr.length(), temp = 0;
		for (int i = 1; i < len - 1; i++)
		{
			char e = arr.at(i);
			if (e == ',')
			{
				d.push_back(temp);
				temp = 0;
			}
			else
			{
				temp *= 10;
				temp += e - '0';
			}
		}
		if (temp != 0) d.push_back(temp);

		for (char cmd : p)
		{
			if (cmd == 'R') rev = !rev;
			else if (cmd == 'D')
			{
				if (d.empty())
				{
					cout << "error";
					errFlag = true;
					break;
				}
				else if (rev == false)
				{
					d.pop_front();
				}
				else
				{
					d.pop_back();
				}
			}
		}

		int size = d.size();
		if (errFlag == false)
		{
			cout << "[";
			while (size-- > 1)
			{
				if (rev == false)
				{
					cout << d.front() << ",";
					d.pop_front();
				}
				else
				{
					cout << d.back() << ",";
					d.pop_back();
				}
			}
			if (!d.empty()) cout << d.front();
			cout << "]";
		}
		cout << "\n";
	}
}