#include <iostream>
using namespace std;

int N, pnt, ans;
int arr[10];
bool poped[10];

void func(int idx, int depth)
{
	int pre = idx - 1, nxt = idx + 1;
	while (poped[pre] == true)
	{
		pre--;
	}
	while (poped[nxt] == true)
	{
		nxt++;
	}
	poped[idx] = true;
	int w = arr[pre] * arr[nxt];
	pnt += w;
	if (depth == N - 2) ans = max(ans, pnt);
	for (int i = 1; i < N - 1; i++)
	{
		if (poped[i] == false)
		{
			func(i, depth + 1);
		}
	}
	poped[idx] = false;
	pnt -= w;
}

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	
	for (int i = 1; i < N - 1; i++)
	{
		func(i, 1);
	}
	cout << ans;
}