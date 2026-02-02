#include <iostream>
using namespace std;

int maxR, maxC;
bool arr[3100][6200];

void func(int depth, int topR, int topC)
{
	if (depth == 3)
	{
		arr[topR][topC] = true;
		arr[topR + 1][topC - 1] = true;
		arr[topR + 1][topC + 1] = true;
		for (int i = -2; i <= 2; i++)
		{
			arr[topR + 2][topC + i] = true;
		}
		maxR = max(maxR, topR + 2);
		maxC = max(maxC, topC + 2);
		return;
	}
	func(depth / 2, topR, topC);
	func(depth / 2, topR + depth / 2, topC - depth / 2);
	func(depth / 2, topR + depth / 2, topC + depth / 2);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	func(N, 0, N - 1);
	for (int i = 0; i <= maxR; i++)
	{
		for (int j = 0; j <= maxC; j++)
		{
			if (arr[i][j] == true) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
}