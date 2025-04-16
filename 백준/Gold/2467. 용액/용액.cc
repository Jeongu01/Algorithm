#include <iostream>
#include <cmath>
using namespace std;

int N;
int arr[100000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int s = 0;
    int e = N - 1;
    int answer = INT32_MAX;
    int answer_s = 0, answer_e = 0;
    while (s < e)
    {
        int sum = arr[s] + arr[e];
        if (abs(answer) >= abs(sum))
        {
            answer = sum;
            answer_s = arr[s];
            answer_e = arr[e];
        }
        if (sum < 0)
            s++;
        else
            e--;
    }

    cout << answer_s << " " << answer_e;

    return 0;
}