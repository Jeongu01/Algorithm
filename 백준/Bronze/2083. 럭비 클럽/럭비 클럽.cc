#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        string name;
        int n, m;
        cin >> name >> n >> m;
        if (name.compare("#") == 0 && n == 0 && m == 0) break;
        if (n > 17) cout << name << " Senior\n";
        else if (m >= 80) cout << name << " Senior\n";
        else cout << name << " Junior\n";
    }
}