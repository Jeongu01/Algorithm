#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        for (int p = 2; p * p <= n; ++p) {
            if (n % p != 0) 
                continue;

            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                cnt++;
            }
            cout << p << " " << cnt << "\n";
        }

        if (n > 1) {
            cout << n << " " << 1 << "\n";
        }
    }
    return 0;
}