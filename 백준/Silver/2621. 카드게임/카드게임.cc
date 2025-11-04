#include <iostream>
using namespace std;

// R B Y G
bool arr[4][10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; i++)
	{
		char c;
		int n;
		cin >> c >> n;
		if (c == 'R') c = 0;
		else if (c == 'B') c = 1;
		else if (c == 'Y') c = 2;
		else c = 3;
		arr[c][n] = true;
	}
	int ans = 0;
	bool flag = false;
	// 1. 5장 같은 색 + 연속
	for (int i = 0; i < 4; i++)
	{
		if (flag == true) break;
		for (int j = 1; j <= 5; j++)
		{
			if (arr[i][j] && arr[i][j + 1] && arr[i][j + 2] && arr[i][j + 3] && arr[i][j + 4] == true)
			{
				flag = true;
				ans = 900 + j + 4;
				break;
			}
		}
	}
	// 2. 4장 같은 숫자
	if (flag == false)
	{
		for (int i = 1; i <= 9; i++)
		{
			if (arr[0][i] && arr[1][i] && arr[2][i] && arr[3][i] == true)
			{
				flag = true;
				ans = 800 + i;
				break;
			}
		}
	}
	// 3. 3장 같은 숫자 + 2장 같은 숫자
	if (flag == false)
	{
		int three = 0, two = 0;
		for (int i = 1; i <= 9; i++)
		{
			int cnt = arr[0][i] + arr[1][i] + arr[2][i] + arr[3][i];
			if (cnt == 3) three = i;
			else if (cnt == 2) two = i;
		}
		if (three != 0 && two != 0)
		{
			flag = true;
			ans = three * 10 + two + 700;
		}
	}	
	// 4. 5장 같은 색
	if (flag == false)
	{
		for (int i = 0; i < 4; i++)
		{
			int cnt = 0, m = 0;
			for (int j = 1; j <= 9; j++)
			{
				if (arr[i][j] == true)
				{
					cnt++;
					m = j;
				}
			}
			if (cnt == 5)
			{
				flag = true;
				ans = 600 + m;
			}
		}
	}
	// 5. 5장 연속 숫자
	if (flag == false)
	{
		int pre = 0, cnt = 0;
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (arr[j][i] == true)
				{
					if (i - 1 == pre) cnt++;
					else cnt = 1;
					pre = i;
				}
			}
		}
		if (cnt == 5)
		{
			flag = true;
			ans = 500 + pre;
		}
	}
	// 6. 3장 같은 숫자
	if (flag == false)
	{
		int three = 0;
		for (int i = 1; i <= 9; i++)
		{
			int cnt = arr[0][i] + arr[1][i] + arr[2][i] + arr[3][i];
			if (cnt == 3) three = i;
		}
		if (three != 0)
		{
			flag = true;
			ans = three + 400;
		}
	}
	// 7. 2장 같은 숫자 + 2장 같은 숫자
	if (flag == false)
	{
		int two1 = 0, two2 = 0;
		for (int i = 1; i <= 9; i++)
		{
			int cnt = arr[0][i] + arr[1][i] + arr[2][i] + arr[3][i];
			if (cnt == 2)
			{
				if (two1 == 0) two1 = i;
				else two2 = i;
			}
		}
		if (two1 != 0 && two2 != 0)
		{
			flag = true;
			ans = two2 * 10 + two1 + 300;
		}
	}
	// 8. 2장 같은 숫자
	if (flag == false)
	{
		int two = 0;
		for (int i = 1; i <= 9; i++)
		{
			int cnt = arr[0][i] + arr[1][i] + arr[2][i] + arr[3][i];
			if (cnt == 2) two = i;
		}
		if (two != 0)
		{
			flag = true;
			ans = two + 200;
		}
	}
	// 9. 아무것도 아닐 때
	if (flag == false)
	{
		int m = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (arr[i][j] == true) m = max(m, j);
			}
		}
		ans = 100 + m;
	}
	cout << ans;
}