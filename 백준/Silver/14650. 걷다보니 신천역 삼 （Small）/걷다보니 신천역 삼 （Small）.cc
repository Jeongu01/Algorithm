#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int N;
    cin >> N;

    if (N == 1) {
        cout << 0 << "\n";
        return 0;
    }

    long long ans = 2;
    for (int i = 0; i < N - 2; ++i) 
        ans *= 3;

    cout << ans << "\n";
    return 0;

}