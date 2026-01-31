#include <iostream>
#include <deque>
using namespace std;

int cnt[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        cnt[s.at(i) - 'A']++;
    }
    int oddCnt = 0;
    char oddAlpha;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2 == 1)
        {
            oddCnt++;
            oddAlpha = 'A' + i;
            cnt[i]--;
        }
    }
    if ((len % 2 == 0 && oddCnt != 0) || (len % 2 == 1 && oddCnt != 1))
    {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    deque<char> ans;
    if (oddCnt == 1) ans.push_back(oddAlpha);
    for (int i = 25; i >= 0; i--)
    {
        int c = cnt[i] / 2;
        for (int j = 0; j < c; j++)
        {
            ans.push_back('A' + i);
            ans.push_front('A' + i);
        }
    }
    for (char a : ans)
    {
        cout << a;
    }
}