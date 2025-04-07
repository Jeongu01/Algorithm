#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

deque<int> D;
int c;

void moveLeft(int target)
{
	c = 0;
	while (D.front() != target)
	{
		D.push_back(D.front());
		D.pop_front();
		c++;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		D.push_back(i);
	}

	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		int t;
		cin >> t;
		
		moveLeft(t);
		D.pop_front();
		answer += min(c, N - c);
		N--;
	}

	cout << answer;

	return 0;
}