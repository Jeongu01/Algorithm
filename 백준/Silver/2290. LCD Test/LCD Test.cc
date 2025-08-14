#include <iostream>
using namespace std;

int s, len;
string n;

void printWidth(int pos)
{
	for (int i = 0; i < len; i++)
	{
		char c = n.at(i);
		switch (pos)
		{
		case 1:
			switch (c)
			{
			case '1':
			case '4':
				for (int j = 0; j < s + 2; j++) cout << " ";
				break;
			default:
				cout << " ";
				for (int j = 0; j < s; j++) cout << "-";
				cout << " ";
				break;
			}
			break;
		case 2:
			switch (c)
			{
			case '0':
			case '1':
			case '7':
				for (int j = 0; j < s + 2; j++) cout << " ";
				break;
			default:
				cout << " ";
				for (int j = 0; j < s; j++) cout << "-";
				cout << " ";
				break;
			}
			break;
		case 3:
			switch (c)
			{
			case '1':
			case '4':
			case '7':
				for (int j = 0; j < s + 2; j++) cout << " ";
				break;
			default:
				cout << " ";
				for (int j = 0; j < s; j++) cout << "-";
				cout << " ";
				break;
			}
			break;
		}
		cout << " ";
	}
	cout << "\n";
}

void printHeight(int pos)
{
	for (int i = 0; i < s; i++)
	{
		for (int l = 0; l < len; l++)
		{
			char c = n.at(l);
			switch (pos)
			{
			case 1:
				switch (c)
				{
				case '1':
				case '2':
				case '3':
				case '7':
					for (int j = 0; j < s + 1; j++) cout << " ";
					cout << "|";
					break;
				case '4':
				case '8':
				case '9':
				case '0':
					cout << "|";
					for (int j = 0; j < s; j++) cout << " ";
					cout << "|";
					break;
				case '5':
				case '6':
					cout << "|";
					for (int j = 0; j < s + 1; j++) cout << " ";
					break;
				}
				break;
			case 2:
				switch (c)
				{
				case '1':
				case '3':
				case '4':
				case '5':
				case '7':
				case '9':
					for (int j = 0; j < s + 1; j++) cout << " ";
					cout << "|";
					break;
				case '6':
				case '8':
				case '0':
					cout << "|";
					for (int j = 0; j < s; j++) cout << " ";
					cout << "|";
					break;
				case '2':
					cout << "|";
					for (int j = 0; j < s + 1; j++) cout << " ";
					break;
				}
				break;
			}
			cout << " ";
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> n;
	len = n.length();
	printWidth(1);
	printHeight(1);
	printWidth(2);
	printHeight(2);
	printWidth(3);
}