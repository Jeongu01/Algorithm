#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> arr, v;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(v.begin(), v.end(), arr[i]);
        if (it == v.end()) v.push_back(arr[i]);
        else *it = arr[i];
    }
    cout << v.size();
}