#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    priority_queue<int> pq;
    int a;
    while (N--)
    {
        cin >> a;
        if (a == 0)
        {
            if (pq.size() == 0) cout << "-1\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            int p;
            for (int i = 0; i < a; i++)
            {
                cin >> p;
                pq.push(p);
            }
        }
    }
}
