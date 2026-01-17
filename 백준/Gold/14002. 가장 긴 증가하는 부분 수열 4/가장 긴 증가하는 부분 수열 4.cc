 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, len;
int index[1000];
int A[1000];
int arr[1000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		auto it = lower_bound(arr, arr + len, A[i]);
		*it = A[i];
		index[i] = it - arr;	// len이 아니야
		if (it == arr + len) len++;
	}
	cout << len << "\n";
	vector<int> ans;
	int idx = len - 1;
	for (int i = N - 1; i >= 0; i--)
	{
		if (index[i] != idx) continue;
		idx--;
		ans.push_back(A[i]);
	}
	reverse(ans.begin(), ans.end());
	for (int i : ans)
	{
		cout << i << " ";
	}
}