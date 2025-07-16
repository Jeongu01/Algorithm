#include <iostream>
using namespace std;

string pwds[100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> pwds[i];
        int len = pwds[i].length();
        for (int j = 0; j <= i; j++)
        {
            int temp = pwds[j].length();
            if (temp != len) continue;
            bool flag = true;
            for (int l = 0; l < len; l++)
            {
                if (pwds[i].at(l) != pwds[j].at(len - 1 - l))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << len << " " << pwds[i].at((len - 1) / 2);
                break;
            }
        }
    }
    
}