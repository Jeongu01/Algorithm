#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    if (s2.length() > s1.length())
    {
        cout << "no";
    }
    else
    {
        cout << "go";
    }
}