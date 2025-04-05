#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

bool visited[1000001];
int F, S, G, U, D, c = 0, answer = -1;	// F층 건물, G층 목표, S층 현재 위치

void bfs()
{
	queue<int> q;
	q.push(S);
	visited[S] = true;

	while (!q.empty())
	{
		int size = q.size();
		c++;

		while (size--)
		{
			int now = q.front();
			q.pop();

			if (now == G)
			{
				answer = c - 1;
				queue<int> temp;
				q = temp;
				break;
			}

			int next = now + U;
			if (next <= F && !visited[next])
			{
				visited[next] = true;
				q.push(next);
			}
			next = now - D;
			if (1 <= next && !visited[next])
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> F >> S >> G >> U >> D;

	bfs();

	if (S == G)
		cout << "0";
	else if (answer == -1)
		cout << "use the stairs";
	else
		cout << answer;
	return 0;
}


