#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool is_prime[110];
vector<int> p;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    fill(is_prime + 2, is_prime + 110, true);
    for (int i = 2; i * i <= 105; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 105; j += i)
                is_prime[j] = false;
        }
    }

    for (int i = 2; i <= 105; i++) {
        if (is_prime[i]) p.push_back(i);
    }

    for (int i = 0; i < p.size() - 1; i++) {
        int res = p[i] * p[i + 1];
        if (res > n) {
            cout << res;
            return 0;
        }
    }

    return 0;
}