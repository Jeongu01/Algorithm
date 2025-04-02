#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	double H, W, N, M;
	cin >> H >> W >> N >> M;
	cout << (int) ceil(H / (N + 1)) * (int) ceil(W / (M + 1));

	return 0;
}