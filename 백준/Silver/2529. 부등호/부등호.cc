#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K;
long long minV = 0x3f3f3f3f3f3f3f3f, maxV = 0;
int arr[10];
char sign[10];
bool used[10];

void func(int depth)
{
	if (depth == K)
	{
		long long value = 0;
		for (int i = 0; i <= K; i++)
		{
			value *= 10;
			value += arr[i];
		}
		minV = min(minV, value);
		maxV = max(maxV, value);
		return;
	}
	char s = sign[depth];
	if (s == '<')
	{
		for (int i = arr[depth] + 1; i < 10; i++)
		{
			if (used[i] == true) continue;
			arr[depth + 1] = i;
			used[i] = true;
			func(depth + 1);
			used[i] = false;
		}
	}
	else
	{
		for (int i = arr[depth] - 1; i >= 0; i--)
		{
			if (used[i] == true) continue;
			arr[depth + 1] = i;
			used[i] = true;
			func(depth + 1);
			used[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> sign[i];
	}
	for (int i = 0; i < 10; i++)
	{
		arr[0] = i;
		used[i] = true;
		func(0);
		used[i] = false;
	}
	long long st = 1;
	for (int i = 0; i < K; i++)
	{
		st *= 10;
	}
	if (st > maxV) cout << "0";
	cout << maxV << "\n";
	if (st > minV) cout << "0";
	cout << minV << "\n";

}