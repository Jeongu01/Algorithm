#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int parents[101];
double stars[101][2];

struct Line
{
	int star1, star2;
	double dist;
	Line(int s1, int s2) : star1(s1), star2(s2)
	{
		dist = sqrt(pow(stars[s1][0] - stars[s2][0], 2) + pow(stars[s1][1] - stars[s2][1], 2));
	}
	bool operator<(const Line l) const
	{
		return this->dist > l.dist;
	}
};

int f(int a)
{
	if (parents[a] == a) return a;
	return parents[a] = f(parents[a]);
}

bool u(int a, int b)
{
	a = f(a);
	b = f(b);
	if (a != b)
	{
		parents[b] = a;
		return true;
	}
	return false;
}

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		parents[i] = i;
	}

	priority_queue<Line> pq;
	for (int i = 0; i < N; i++)
	{
		double x, y;
		cin >> x >> y;
		stars[i][0] = x;
		stars[i][1] = y;

		for (int j = 0; j < i; j++)
		{
			pq.push(Line(i, j));
		}
	}

	int cnt = 0;
	double ans = 0;
	while (cnt < N - 1)
	{
		Line cur = pq.top();
		pq.pop();
		int star1 = cur.star1;
		int star2 = cur.star2;
		if (u(star1, star2))
		{
			cnt++;
			ans += cur.dist;
		}
	}

	printf("%.2f", ans);
}