#include <iostream>
using namespace std;

int N, M, sum;
int cards[100][2];
bool isBack[100];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> cards[i][0] >> cards[i][1];
	}
	int K;
	for (int i = 0; i < M; i++)
	{
		cin >> K;
		for (int j = 0; j < N; j++)
		{
			if (cards[j][isBack[j]] <= K) isBack[j] = !isBack[j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		sum += cards[i][isBack[i]];
	}
	cout << sum;
}