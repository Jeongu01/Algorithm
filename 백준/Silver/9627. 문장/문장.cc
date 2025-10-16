#include <iostream>
using namespace std;

string words[20];
string one_to_nineteen[] = {
	"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
	"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
	"sixteen", "seventeen", "eighteen", "nineteen"
};
string tens[] = {
	"", "", "twenty", "thirty", "forty", "fifty",
	"sixty", "seventy", "eighty", "ninety"
};

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	int N, s_len = 0, num_pos = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> words[i];
		if (words[i].compare("$") == 0)
		{
			num_pos = i;
			continue;
		}
		int w_len = words[i].length();
		s_len += w_len;
	}

	for (int i = 1; i < 1000; i++)
	{
		string num;
		if (i < 20)
		{
			num = one_to_nineteen[i];
		}
		else if (i < 100)
		{
			int ten = i / 10, one = i % 10;
			num = tens[ten] + one_to_nineteen[one];
		}
		else
		{
			int h = i / 100, rem = i % 100;
			num = one_to_nineteen[h] + "hundred";
			if (rem == 0);
			else if (rem < 20) num += one_to_nineteen[rem];
			else
			{
				int ten = rem / 10, one = rem % 10;
				num += tens[ten] + one_to_nineteen[one];
			}
		}
		if (s_len + num.length() != i) continue;
		words[num_pos] = num;
		break;
	}
	for (int i = 0; i < N; i++)
	{
		cout << words[i] << " ";
	}
}