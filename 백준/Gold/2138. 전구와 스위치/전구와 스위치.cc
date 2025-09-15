#include <iostream>
#include <queue>
using namespace std;

int N;
bool arr[100'001], arr2[100'001], target[100'001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	string org; cin >> org;
	for (int i = 0; i < N; i++)
	{
		arr[i] = org.at(i) - '0';
		arr2[i] = arr[i];
	}
	string trg; cin >> trg;
	for (int i = 0; i < N; i++)
	{
		target[i] = trg.at(i) - '0';
	}

	int ans = 0;
	for (int i = 1; i < N; i++)
	{
		if (arr[i - 1] != target[i - 1])
		{
			arr[i] = !arr[i];
			if (i != N - 1) arr[i + 1] = !arr[i + 1];
			ans++;
		}
	}
	if (arr[N - 1] != target[N - 1]) ans = -1;

	int ans2 = 1;
	arr2[0] = !arr2[0]; arr2[1] = !arr2[1];
	for (int i = 1; i < N; i++)
	{
		if (arr2[i - 1] != target[i - 1])
		{
			arr2[i] = !arr2[i];
			if (i != N - 1) arr2[i + 1] = !arr2[i + 1];
			ans2++;
		}
	}
	if (arr2[N - 1] != target[N - 1]) ans2 = -1;
	if (ans == -1) ans = ans2;
	else if (ans2 != -1) ans = min(ans, ans2);
	cout << ans;
}