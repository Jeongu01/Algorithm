#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, L;
vector<int> v;
struct Dist
{
	int dist, cnt;
	Dist(int dist) : dist(dist), cnt(1) {}
	bool operator<(const Dist d) const
	{
		int d1 = this->dist / this->cnt;
		if (this->dist % this->cnt != 0) d1++;
		int d2 = d.dist / d.cnt;
		if (d.dist % d.cnt != 0) d2++;
		return d1 < d2;
	}
};
priority_queue<Dist> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> L;
	for (int i = 0; i < N; i++)
	{
		int pos;
		cin >> pos;
		v.push_back(pos);
	}
	v.push_back(0);
	v.push_back(L);
	sort(v.begin(), v.end());
	for (int i = 0; i < N + 1; i++)
	{
		pq.push(Dist(v[i + 1] - v[i]));
	}
	while (M--)
	{
		Dist cur = pq.top();
		pq.pop();
		cur.cnt++;
		pq.push(cur);
	}
	Dist ans = pq.top();
	int m = ans.dist / ans.cnt;
	if (ans.dist % ans.cnt != 0) m++;
	cout << m;
}