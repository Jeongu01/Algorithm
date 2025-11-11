#include <iostream>
using namespace std;

int main()
{
	int N, pnt, P, rnk = 1, cnt = 0;
	cin >> N >> pnt >> P;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		if (pnt <= input) cnt++;
		if (pnt < input) rnk++;
	}
	if (cnt < P) cout << rnk;
	else cout << "-1";
}