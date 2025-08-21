#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string S, E, Q;
	int s1, s2, e1, e2, q1, q2;
	cin >> S >> E >> Q;
	s1 = stoi(S.substr(0, 2));
	s2 = stoi(S.substr(3, 5));
	e1 = stoi(E.substr(0, 2));
	e2 = stoi(E.substr(3, 5));
	q1 = stoi(Q.substr(0, 2));
	q2 = stoi(Q.substr(3, 5));

	map<string, bool> in, out;
	while (true)
	{
		string t, name;
		cin >> t >> name;
		if (t == "" && name == "") break;
		int t1, t2;
		t1 = stoi(t.substr(0, 2));
		t2 = stoi(t.substr(3, 5));

		if (t1 < s1) in.insert(make_pair(name, true));
		else if (t1 == s1 && t2 <= s2) in.insert(make_pair(name, true));
		else if (e1 < t1)
		{
			if (t1 < q1 && in[name] == true) out.insert(make_pair(name, true));
			else if (t1 == q1 && t2 <= q2 && in[name] == true) out.insert(make_pair(name, true));
		}
		else if (e1 == t1 && e2 <= t2)
		{
			if (t1 < q1 && in[name] == true) out.insert(make_pair(name, true));
			else if (t1 == q1 && t2 <= q2 && in[name] == true) out.insert(make_pair(name, true));
		}
	}
	cout << out.size();
}