#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char c;
    cin >> c;
    if (c == 'N' || c == 'n') cout << "Naver D2";
    else cout << "Naver Whale";
}