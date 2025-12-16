#include <iostream>
#include <set>
using namespace std;

int N, M, s;
set<int> st;
int arr[8];

void func(int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (auto e : st)
    {
        arr[depth] = e;
        func(depth + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        st.insert(input);
    }
    func(0);
}