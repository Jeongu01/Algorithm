#include <iostream>
using namespace std;

bool ans;
int arr[6][3];
int temp[6][3];

bool check()
{
	ans = true;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ans &= arr[i][j] == temp[i][j];
		}
	}
	return ans;
}

bool play(int t1, int t2)
{
	bool ret = false;
	int nxt_t1 = t1, nxt_t2 = t2 + 1;
	if (nxt_t2 == 6)
	{
		nxt_t1++;
		nxt_t2 = nxt_t1 + 1;
	}
	// t1 승
	temp[t1][0]++;
	temp[t2][2]++;
	if (t1 == 4 && t2 == 5) ret |= check();
	else ret |= play(nxt_t1, nxt_t2);
	temp[t1][0]--;
	temp[t2][2]--;
	// 무
	temp[t1][1]++;
	temp[t2][1]++;
	if (t1 == 4 && t2 == 5) ret |= check();
	else ret |= play(nxt_t1, nxt_t2);
	temp[t1][1]--;
	temp[t2][1]--;
	// t1 패
	temp[t1][2]++;
	temp[t2][0]++;
	if (t1 == 4 && t2 == 5) ret |= check();
	else ret |= play(nxt_t1, nxt_t2);
	temp[t1][2]--;
	temp[t2][0]--;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 4; i++)
	{
		ans = true;
		for (int t = 0; t < 6; t++)
		{
			for (int w = 0; w < 3; w++)
			{
				cin >> arr[t][w];
			}
		}
		if (play(0, 1)) cout << 1 << " ";
		else cout << 0 << " ";
	}
}