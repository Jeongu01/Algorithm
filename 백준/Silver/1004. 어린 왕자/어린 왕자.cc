#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int x1, y1, x2, y2;	// 출발점, 도착점
		cin >> x1 >> y1 >> x2 >> y2;

		int n;	// 행성계 개수
		cin >> n;

		int count = 0;
		for (int j = 0; j < n; j++)
		{
			int cx, cy, r;	// 행성계의 중점과 반지름
			cin >> cx >> cy >> r;

			bool inRange1, inRange2;

			inRange1 = pow(cx - x1, 2) + pow(cy - y1, 2) < pow(r, 2);
			inRange2 = pow(cx - x2, 2) + pow(cy - y2, 2) < pow(r, 2);

			if (inRange1^inRange2)
			{
				count++;
			}
		}

		cout << count << "\n";
	}

	return 0;
}