#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = n / 5; i >= 0; i--) {
        int a = n - 5 * i;
        if (a % 2 == 0) {
            cout << i + (a / 2) << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}