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
        int N, M;
        cin >> N >> M;

        int U = (M * 2) - N;
        int V = M - U;

        cout << U << " " << V << "\n";
    }
}