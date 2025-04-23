#include <iostream>
using namespace std;

int N, cnt = 0;
int arrow[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        if (arrow[input] == 0)
        {
            arrow[input - 1]++;
            cnt++;
        }
        else
        {
            arrow[input]--;
            arrow[input - 1]++;
        }
    }

    cout << cnt;
}