#include <iostream>
using namespace std;

int N;
int team1[300], team2[300];

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> team1[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> team2[i];
	}
	int win1 = 0, win2 = 0, ans = 0;
	for (int i = 0; i < N; i++)
	{
		// team1 승리
		if (
			(team1[i] == 1 && team2[i] == 3) || 
			(team1[i] == 2 && team2[i] == 1) || 
			(team1[i] == 3 && team2[i] == 2) ||
			(team1[i] == team2[i] && win1 < win2))
		{
			win1++;
			ans = max(ans, win2);
			win2 = 0;
		}
		// team2 승리
		else if (
			(team1[i] == 3 && team2[i] == 1) || 
			(team1[i] == 1 && team2[i] == 2) || 
			(team1[i] == 2 && team2[i] == 3) ||
			(team1[i] == team2[i] && win1 > win2))
		{
			win2++;
			ans = max(ans, win1);
			win1 = 0;
		}
	}
	ans = max(ans, win1);
	ans = max(ans, win2);
	cout << ans;
}