#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<int> st;
    string input;
    cin >> input;
    int len = input.length();
    for (int i = 0; i < len; i++)
    {
        char c = input.at(i);
        switch (c)
        {
        case '(':
            st.push(-1);
            break;
        case ')':
        {
            if (st.empty()) { cout << "0"; return 0; }
            int t = st.top();
            if (t == -1)
            {
                st.pop();
                if (st.empty()) st.push(2);
                else
                {
                    int t2 = st.top();
                    if (t2 != -1 && t2 != -2)
                    {
                        int v = t2; st.pop();
                        st.push(v + 2);
                    }
                    else st.push(2);
                }
            }
            else if (t == -2) { cout << "0"; return 0; }
            else
            {
                int v = t; st.pop();
                if (st.empty()) { cout << "0"; return 0; }
                int t2 = st.top(); st.pop();
                if (t2 == -1)
                {
                    if (st.empty()) st.push(2 * v);
                    else
                    {
                        int t3 = st.top();
                        if (t3 != -1 && t3 != -2)
                        {
                            int v2 = t3; st.pop();
                            st.push(v2 + 2 * v);
                        }
                        else st.push(2 * v);
                    }
                }
                else if (t2 == -2) { cout << "0"; return 0; }
            }
            break;
        }
        case '[':
            st.push(-2);
            break;
        case ']':
        {
            if (st.empty()) { cout << "0"; return 0; }
            int t = st.top();
            if (t == -2)
            {
                st.pop();
                if (st.empty()) st.push(3);
                else
                {
                    int t2 = st.top();
                    if (t2 != -1 && t2 != -2)
                    {
                        int v = t2; st.pop();
                        st.push(v + 3);
                    }
                    else st.push(3);
                }
            }
            else if (t == -1) { cout << "0"; return 0; }
            else
            {
                int v = t; st.pop();
                if (st.empty()) { cout << "0"; return 0; }
                int t2 = st.top(); st.pop();
                if (t2 == -2)
                {
                    if (st.empty()) st.push(3 * v);
                    else
                    {
                        int t3 = st.top();
                        if (t3 != -1 && t3 != -2)
                        {
                            int v2 = t3; st.pop();
                            st.push(v2 + 3 * v);
                        }
                        else st.push(3 * v);
                    }
                }
                else if (t2 == -1) { cout << "0"; return 0; }
            }
            break;
        }
        }
    }
    if (st.size() != 1 || st.top() < 0) cout << "0";
    else cout << st.top();
    
}