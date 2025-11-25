#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		double input;
		cin >> input;
		v.push_back((int)(input * 10));
	}
	sort(v.begin(), v.end());
	int end = N - K;
	int sum = 0;
	for (int i = K; i < end; i++)
	{
		sum += v[i];
	}
	double avg = ((double)sum / 10) / (N - K - K);
	double ans1 = round(avg * 100.0) / 100.0;
	printf("%0.2f\n", ans1);
	for (int i = 0; i < K; i++)
	{
		sum += v[K];
		sum += v[N - K - 1];
	}
	avg = ((double)sum / 10) / N;
	double ans2 = round(avg * 100.0) / 100.0;
	printf("%0.2f\n", ans2);
}