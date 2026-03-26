#include <iostream>
#include <algorithm>
using namespace std;

int costs[1000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        if (A >= N) costs[i] = 0;
        else costs[i] = N - A;
    }

    sort(costs, costs + M);

    int sum = 0;
    for (int i = 0; i < M - 1; i++) {
        sum += costs[i];
    }

    cout << sum;
}