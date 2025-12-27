#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unordered_map<string, vector<string>> gtom;
    unordered_map<string, string> mtog;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string group;
        cin >> group;
        int num;
        cin >> num;
        vector<string> members;
        for (int j = 0; j < num; j++)
        {
            string member;
            cin >> member;
            members.push_back(member);
            mtog.insert({ member, group });
        }
        sort(members.begin(), members.end());
        gtom.insert({ group, members });
    }
    for (int i = 0; i < M; i++)
    {
        string input;
        cin >> input;
        int num;
        cin >> num;
        if (num == 0)
        {
            vector<string> g = gtom[input];
            for (string m : g)
            {
                cout << m << "\n";
            }
        }
        else
        {
            cout << mtog[input] << "\n";
        }
    }
}