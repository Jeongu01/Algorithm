#include <iostream>
#include <queue>
using namespace std;

int n, s;
int arr[100'001];
bool visited[100'001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	cin >> s;
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		int nxtl = cur - arr[cur];
		int nxtr = cur + arr[cur];
		if (1 <= nxtl && visited[nxtl] == false)
		{
			q.push(nxtl);
			visited[nxtl] = true;
		}
		if (nxtr <= n && visited[nxtr] == false)
		{
			q.push(nxtr);
			visited[nxtr] = true;
		}

	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == true) cnt++;
	}
	cout << cnt;
}