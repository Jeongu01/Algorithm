#include <iostream>
#include <cstring>
using namespace std;

int N, M, cur = 100, ans;
bool btn[10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	memset(btn, true, sizeof(btn));
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		btn[num] = false;
	}
	ans = abs(N - cur);
	if (N == 0)
	{
		int num = -1;
		for (int i = 0; i < 10; i++)
		{
			if (btn[i] == true)
			{
				num = i;
				break;
			}
		}
		if (num != -1) ans = num + 1;
	}
	else
	{
		// 숫자 버튼
		{
			int temp = N, cnt = 0;
			bool flag = true;
			while (temp > 0 && flag == true)
			{
				if (btn[temp % 10] == false) flag = false;
				cnt++;
				temp /= 10;
			}
			if (flag == true) ans = min(ans, cnt);
		}
		// 숫자 버튼 + 버튼
		for (int i = N - 1; i > 0; i--)
		{
			if (N - i >= ans) break;
			int temp = i, cnt = 0;
			bool flag = true;
			while (temp > 0 && flag == true)
			{
				if (btn[temp % 10] == false) flag = false;
				cnt++;
				temp /= 10;
			}
			if (flag == true) ans = min(ans, cnt + N - i);
		}
		// 0 버튼 + 버튼
		{
			if (btn[0] == true) ans = min(ans, N + 1);
		}
		// 숫자 버튼 - 버튼
		for (int i = N + 1; i < 0x3f3f3f3f; i++)
		{
			if (i - N >= ans) break;
			int temp = i, cnt = 0;
			bool flag = true;
			while (temp > 0 && flag == true)
			{
				if (btn[temp % 10] == false) flag = false;
				cnt++;
				temp /= 10;
			}
			if (flag == true) ans = min(ans, cnt + i - N);
		}
	}
	cout << ans;
}