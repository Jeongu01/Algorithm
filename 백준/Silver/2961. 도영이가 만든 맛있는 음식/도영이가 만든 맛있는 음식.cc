#include <iostream>
using namespace std;

int N, ans = 0x3f3f3f3f;
int S[10], B[10];

void func(int idx, int s, int b, bool isVisited)
{
    if (idx == N)
    {
        if (isVisited) ans = min(ans, abs(s - b));
        return;
    }
    func(idx + 1, s * S[idx], b + B[idx], true);
    func(idx + 1, s, b, isVisited);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> S[i] >> B[i];
    }
    func(0, 1, 0, false);
    cout << ans;
}