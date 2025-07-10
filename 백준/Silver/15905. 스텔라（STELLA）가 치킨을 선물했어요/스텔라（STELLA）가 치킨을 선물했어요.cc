#include <iostream>
#include <queue>
using namespace std;

struct Point
{
    int solved;
    int penalty;
    Point(int s, int p) : solved(s), penalty(p) {}
    bool operator<(const Point p) const
    {
        if (this->solved != p.solved) return this->solved < p.solved;
        else return this->penalty > p.penalty;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<Point> pq;
    int N;
    cin >> N;
    while (N--)
    {
        int s, p;
        cin >> s >> p;
        pq.push(Point(s, p));
    }
    for (int i = 0; i < 4; i++)
    {
        pq.pop();
    }
    Point fifth = pq.top();
    pq.pop();
    int ans = 0;
    while (!pq.empty())
    {
        Point cur = pq.top();
        pq.pop();
        if (cur.solved == fifth.solved) ans++;
    }
    cout << ans;
}