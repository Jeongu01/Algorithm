#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unordered_map<int, int> A;
    vector<int> ans;
    int d = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        A.insert({ input, i });
    }
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        auto a = A.find(input);
        int u = (*a).second - i;
        if (u > d)
        {
            ans.clear();
            ans.push_back(input);
            d = u;
        }
        else if (u == d)
        {
            ans.push_back(input);
        }
    }

    for (auto e : ans)
    {
        cout << e << " ";
    }
}