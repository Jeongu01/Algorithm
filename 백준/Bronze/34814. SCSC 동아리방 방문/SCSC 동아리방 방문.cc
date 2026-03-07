#include <iostream>
using namespace std;

int a[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> a[i];

    for (int j = 0; j < M; j++) {
        int l, h;
        cin >> l >> h;

        int mx = 0;
        for (int i = 1; i <= N; i++) {
            mx = max(mx, a[i]);
        }

        if (a[h] != mx) {
            a[l]--;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << a[i];
        if (i < N) cout << ' ';
    }
    cout << '\n';

    return 0;
}