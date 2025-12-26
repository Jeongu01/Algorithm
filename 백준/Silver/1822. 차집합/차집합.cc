#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nA, nB;
int A[500'000];
int B[500'000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> nA >> nB;
    for (int i = 0; i < nA; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < nB; i++)
    {
        cin >> B[i];
    }
    sort(B, B + nB);
    vector<int> ans;
    for (int i = 0; i < nA; i++)
    {
        auto p = lower_bound(B, B + nB, A[i]);
        if (*p != A[i]) ans.push_back(A[i]);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto e : ans)
    {
        cout << e << " ";
    }
}