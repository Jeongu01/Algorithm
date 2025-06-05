#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> A;
int N;
long long B;

vector<vector<int>> mulArr(vector<vector<int>> a, vector<vector<int>> b)
{
	vector<vector<int>> arr;
	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		for (int j = 0; j < N; j++)
		{
			temp.push_back(0);
			for (int k = 0; k < N; k++)
			{
				temp[j] += a[i][k] * b[k][j];
				temp[j] %= 1000;
			}
		}
		arr.push_back(temp);
	}
	return arr;
}

vector<vector<int>> sqrArr(vector<vector<int>> arr, long long X)
{
	if (X == 1) return arr;
	vector<vector<int>> sArr = sqrArr(arr, X / 2);
	sArr = mulArr(sArr, sArr);
	if (X % 2 == 1) return mulArr(sArr, arr);
	else return sArr;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int input;
	cin >> N >> B;
	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		for (int j = 0; j < N; j++)
		{
			cin >> input;
			temp.push_back(input % 1000);
		}
		A.push_back(temp);
	}

	vector<vector<int>> ans = sqrArr(A, B);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}