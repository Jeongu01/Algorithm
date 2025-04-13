#include <iostream>
#include <string>
using namespace std;

int arr[64][64];

string func(int size, int sr, int sc)
{
	int st = arr[sr][sc];
	bool p = true;
	for (int i = sr; i < sr + size; i++)
	{
		for (int j = sc; j < sc + size; j++)
		{
			p &= st == arr[i][j];
		}
	}
	if (p)
		return to_string(st);
	else
	{
		string ret;
		ret.append("(");
		ret.append(func(size / 2, sr, sc));
		ret.append(func(size / 2, sr, sc + size / 2));
		ret.append(func(size / 2, sr + size / 2, sc));
		ret.append(func(size / 2, sr + size / 2, sc + size / 2));
		ret.append(")");
		return ret;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = input.at(j) - '0';
		}
	}

	cout << func(N, 0, 0);

	return 0;
}