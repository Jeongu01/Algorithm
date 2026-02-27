#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const string& s1, const string& s2)
{
	int len1 = s1.length();
	int len2 = s2.length();
	if (len1 < len2)
		return true;
	if (len1 > len2)
		return false;
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < len1; i++)
	{
		char c1 = s1.at(i);
		char c2 = s2.at(i);
		if ('0' <= c1 && c1 <= '9')
			sum1 += c1 - '0';
		if ('0' <= c2 && c2 <= '9')
			sum2 += c2 - '0';
	}
	if (sum1 < sum2)
		return true;
	if (sum1 > sum2)
		return false;
	return s1 < s2;
}

string arr[50];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "\n";
	}
}