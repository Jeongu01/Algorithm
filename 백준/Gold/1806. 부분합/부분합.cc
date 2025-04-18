#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> arr;
vector<int> prefixSum;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, S, input;
    cin >> N >> S;

    arr.push_back(0);
    prefixSum.push_back(0);
    for (int i = 1; i <= N; i++)
    {
        cin >> input;
        arr.push_back(input);
        prefixSum.push_back(input + prefixSum[i - 1]);
    }

    int p1 = 0, p2 = 0, answer = INT32_MAX;
    while (p2 <= N)
    {
        int sum = prefixSum[p2] - prefixSum[p1];
        if (sum < S)
        {
            p2++;
        }
        else
        {
            answer = min(answer, p2 - p1);
            p1++;
        }
    }

    if (answer == INT32_MAX) answer = 0;
    cout << answer;

    return 0;
}