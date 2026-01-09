#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int> maxQ, minQ;
	int n, input;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (minQ.empty())
		{
			minQ.push(input);
		}
		else if (maxQ.empty())
		{
			int minMax = minQ.top();
			if (minMax > input)
			{
				maxQ.push(-minMax);
				minQ.pop();
				minQ.push(input);
			}
			else maxQ.push(-input);
		}
		else if (i % 2 == 0)
		{
			int maxMin = -maxQ.top();
			if (maxMin < input)
			{
				maxQ.push(-input);
				maxQ.pop();
				minQ.push(maxMin);
			}
			else minQ.push(input);
		}
		else
		{
			int minMax = minQ.top();
			minQ.push(input);
			minMax = minQ.top();
			minQ.pop();
			maxQ.push(-minMax);
		}
		cout << minQ.top() << "\n";
	}
}