#include <iostream>
using namespace std;

bool alpha[30];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S, T;
    cin >> S >> T;
    for (char c : S)
    {
        alpha[c - 'a'] = true;
    }
    for (char c : T)
    {
        if (!alpha[c - 'a']) cout << c;
    }
}