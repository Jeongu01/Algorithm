#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[8];
int p[8];

void func(int depth, int start)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << p[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = start; i < N; i++)
    {
        if (p[depth - 1] > arr[i])
            continue;
        p[depth] = arr[i];
        func(depth + 1, i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);
    for (int i = 0; i < N; i++)
    {
        p[0] = arr[i];
        func(1, 0);
    }
}