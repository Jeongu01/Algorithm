#include <iostream>
#include <vector>
using namespace std;

/*
* 에라토스테네스의 채
* 구간합
* 두 포인터
*/
bool arr[4000001];

int main()
{
	vector<int> v;	// 28만개
	// 에라토스테네스의 채
	arr[0] = arr[1] = true;
	for (int  i = 2; i <= 4000000; i++)
	{
		if (arr[i] == false)
		{
			v.push_back(i);
			for (int j = i + i; j <= 4000000; j += i)
			{
				arr[j] = true;
			}
		}
	}

	// 구간합
	vector<long long> ps(v.size() + 1);
	ps[0] = 0;
	for (int i = 1; i <= v.size(); i++)
	{
		ps[i] = ps[i - 1] + v[i - 1];
	}
	
	int N;
	cin >> N;

	// 두 포인터
	int answer = 0, s = 0, e = 1;
	while (s < e)
	{
		long long sum = ps[e] - ps[s];

		if (sum == N)
		{
			answer++;
			e++;
		}
		else if (sum < N)
			e++;
		else
			s++;
	}

	cout << answer;

	return 0;
}