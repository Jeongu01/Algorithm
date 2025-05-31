#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int N, M, K;
int c[30001];
int parents[30001];
map<int, int> childCnt;
int dp[30001][3001];

int f(int a)
{
	if (parents[a] == a) return a;
	return parents[a] = f(parents[a]);
}

void u(int a, int b)
{
	a = f(a);
	b = f(b);
	if (a != b)
	{
		c[a] += c[b];
		childCnt[a] += childCnt[b];
		parents[b] = a;
	}
}

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> M >> K;
   for (int i = 1; i <= N; i++)
   {
	   childCnt[i] = 1;
	   parents[i] = i;
	   cin >> c[i];
   }

   for (int i = 0; i < M; i++)
   {
	   int a, b;
	   cin >> a >> b;
	   u(a, b);
   }

   set<int> s;
   for (int i = 1; i <= N; i++)
   {
	   s.insert(f(i));
   }
   vector<int> group;
   for (int e : s)
   {
	   group.push_back(e);
   }

   int size = group.size();
   for (int i = childCnt[group[0]]; i < K; i++)
   {
	   dp[0][i] = c[group[0]];
   }
   for (int i = 1; i < size; i++)
   {
	   int cur = group[i];
	   int cnt = childCnt[cur];
	   int candy = c[cur];
	   for (int j = 0; j < K; j++)
	   {
		   if (cnt <= j) dp[i][j] = max(dp[i - 1][j], candy + dp[i - 1][j - cnt]);
		   else dp[i][j] = dp[i - 1][j];
	   }
   }

   cout << dp[size - 1][K - 1];
}