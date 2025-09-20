#include <iostream>
using namespace std;

int arr[5];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	int len = s.length(), ans = 0;
	bool flag = true;
	for (int i = 0; i < len && flag == true; i++)
	{
		char c = s.at(i);
		switch (c)
		{
		case 'q':
			if (arr[4] == 0) ans++;
			else arr[4]--;
			arr[0]++;
			break;
		case 'u':
			if (arr[0] == 0) flag = false;
			arr[0]--;
			arr[1]++;
			break;
		case 'a':
			if (arr[1] == 0) flag = false;
			arr[1]--;
			arr[2]++;
			break;
		case 'c':
			if (arr[2] == 0) flag = false;
			arr[2]--;
			arr[3]++;
			break;
		case 'k':
			if (arr[3] == 0) flag = false;
			arr[3]--;
			arr[4]++;
			break;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (arr[i] != 0) flag = false;
	}
	if (flag == false) cout << "-1";
	else cout << ans;
}