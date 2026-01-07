#include <iostream>
#include <map>
using namespace std;

int N, M, B;
map<int, int> arr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> B;
	int input;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> input;
			arr[input]++;
		}
	}
	int ansT = 0x3f3f3f3f, ansH = 0;
	for (auto target : arr)
	{
		int trgH = target.first;
		int trgCnt = target.second;
		int t = 0, cnt = -B;
		for (int h = 0; h <= 256; h++)
		{
			int c = arr[h];
			cnt += (trgH - h) * c;
			if (trgH - h > 0)
			{
				t += (trgH - h) * c;
			}
			else if (trgH - h < 0)
			{
				t += (h - trgH) * c * 2;
			}
		}
		if (cnt > 0) continue;
		if (ansT >= t)
		{
			ansT = t;
			ansH = max(ansH, trgH);
		}
	}
	cout << ansT << " " << ansH;
}