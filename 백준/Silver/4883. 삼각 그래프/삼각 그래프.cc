#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int k = 0;
	while (true)
	{
		k++;
		int N;
		cin >> N;
		if (N == 0) return 0;
		int pl, pc, pr, l, c, r;
		cin >> pl >> pc >> pr;
		pr += pc;
		cin >> l >> c >> r;
		l += pc;
		c += min(min(pc, pr), l);
		r += min(min(pc, pr), c);
		pl = l; pc = c; pr = r;
		for (int i = 2; i < N; i++)
		{
			cin >> l >> c >> r;
			l += min(pl, pc);
			c += min(min(min(pl, pc), pr), l);
			r += min(min(pc, pr), c);
			pl = l; pc = c; pr = r;
		}
		cout << k << ". " << pc << "\n";
	}
}