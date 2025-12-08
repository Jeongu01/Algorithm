#include <iostream>
#include <queue>
#include <set>
using namespace std;
#define POS pair<pair<int, int>, pair<int, int>>

int N, M;
char arr[10][10];
set<POS> visited;

POS UpDown(int dr, int redR, int redC, int blueR, int blueC);
POS LeftRight(int dc, int redR, int redC, int blueR, int blueC);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int redR, redC, blueR, blueC, holeR = 0, holeC = 0;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            char c = s.at(j);
            if (c == '#' || c == '.') arr[i][j] = c;
            else if (c == 'R')
            {
                redR = i;
                redC = j;
                arr[i][j] = '.';
            }
            else if (c == 'B')
            {
                blueR = i;
                blueC = j;
                arr[i][j] = '.';
            }
            else if (c == 'O')
            {
                holeR = i;
                holeC = j;
                arr[i][j] = 'O';
            }
        }
    }
    visited.insert({ {redR, redC}, {blueR, blueC} });
    queue<int> q;
    q.push(redR);
    q.push(redC);
    q.push(blueR);
    q.push(blueC);
    int cnt = 0;
    while (!q.empty())
    {
        int size = q.size();
        size /= 4;
        cnt++;
        if (cnt > 10)
        {
            cout << -1;
            return 0;
        }
        while (size--)
        {
            int credR = q.front(); q.pop();
            int credC = q.front(); q.pop();
            int cblueR = q.front(); q.pop();
            int cblueC = q.front(); q.pop();
            POS nxt;
            int nredR, nredC, nblueR, nblueC;
            nxt = UpDown(-1, credR, credC, cblueR, cblueC);
            nredR = nxt.first.first; nredC = nxt.first.second; nblueR = nxt.second.first; nblueC = nxt.second.second;
            if (nblueR == holeR && nblueC == holeC);
            else if (nredR == holeR && nredC == holeC)
            {
                cout << cnt;
                return 0;
            }
            else if (visited.find(nxt) == visited.end())
            {
                visited.insert(nxt);
                q.push(nredR);
                q.push(nredC);
                q.push(nblueR);
                q.push(nblueC);
            }
            nxt = UpDown(1, credR, credC, cblueR, cblueC);
            nredR = nxt.first.first; nredC = nxt.first.second; nblueR = nxt.second.first; nblueC = nxt.second.second;
            if (nblueR == holeR && nblueC == holeC);
            else if (nredR == holeR && nredC == holeC)
            {
                cout << cnt;
                return 0;
            }
            else if (visited.find(nxt) == visited.end())
            {
                visited.insert(nxt);
                q.push(nredR);
                q.push(nredC);
                q.push(nblueR);
                q.push(nblueC);
            }
            nxt = LeftRight(-1, credR, credC, cblueR, cblueC);
            nredR = nxt.first.first; nredC = nxt.first.second; nblueR = nxt.second.first; nblueC = nxt.second.second;
            if (nblueR == holeR && nblueC == holeC);
            else if (nredR == holeR && nredC == holeC)
            {
                cout << cnt;
                return 0;
            }
            else if (visited.find(nxt) == visited.end())
            {
                visited.insert(nxt);
                q.push(nredR);
                q.push(nredC);
                q.push(nblueR);
                q.push(nblueC);
            }
            nxt = LeftRight(1, credR, credC, cblueR, cblueC);
            nredR = nxt.first.first; nredC = nxt.first.second; nblueR = nxt.second.first; nblueC = nxt.second.second;
            if (nblueR == holeR && nblueC == holeC);
            else if (nredR == holeR && nredC == holeC)
            {
                cout << cnt;
                return 0;
            }
            else if (visited.find(nxt) == visited.end())
            {
                visited.insert(nxt);
                q.push(nredR);
                q.push(nredC);
                q.push(nblueR);
                q.push(nblueC);
            }
        }
    }
    cout << -1;
}

POS UpDown(int dr, int redR, int redC, int blueR, int blueC)
{
    int nredR = redR, nredC = redC, nblueR = blueR, nblueC = blueC;
    if (dr * redR > dr * blueR)
    {
        while (true)
        {
            nredR += dr;
            if (arr[nredR][nredC] == '.') continue;
            if (arr[nredR][nredC] != 'O') nredR -= dr;
            break;
        }
        while (true)
        {
            nblueR += dr;
            if (arr[nblueR][nblueC] == 'O') break;
            if (arr[nblueR][nblueC] != '.' || (nblueR == nredR && nblueC == nredC))
            {
                nblueR -= dr;
                break;
            }
        }
    }
    else
    {
        while (true)
        {
            nblueR += dr;
            if (arr[nblueR][nblueC] == '.') continue;
            if (arr[nblueR][nblueC] != 'O') nblueR -= dr;
            break;
        }
        while (true)
        {
            nredR += dr;
            if (arr[nredR][nredC] == 'O') break;
            if (arr[nredR][nredC] != '.' || (nblueR == nredR && nblueC == nredC))
            {
                nredR -= dr;
                break;
            }
        }
    }
    return { {nredR, nredC}, {nblueR, nblueC} };
}

POS LeftRight(int dc, int redR, int redC, int blueR, int blueC)
{
    int nredR = redR, nredC = redC, nblueR = blueR, nblueC = blueC;
    if (dc * redC > dc * blueC)
    {
        while (true)
        {
            nredC += dc;
            if (arr[nredR][nredC] == '.') continue;
            if (arr[nredR][nredC] != 'O') nredC -= dc;
            break;
        }
        while (true)
        {
            nblueC += dc;
            if (arr[nblueR][nblueC] == 'O') break;
            if (arr[nblueR][nblueC] != '.' || (nblueR == nredR && nblueC == nredC))
            {
                nblueC -= dc;
                break;
            }
        }
    }
    else
    {
        while (true)
        {
            nblueC += dc;
            if (arr[nblueR][nblueC] == '.') continue;
            if (arr[nblueR][nblueC] != 'O') nblueC -= dc;
            break;
        }
        while (true)
        {
            nredC += dc;
            if (arr[nredR][nredC] == 'O') break;
            if (arr[nredR][nredC] != '.' || (nblueR == nredR && nblueC == nredC))
            {
                nredC -= dc;
                break;
            }
        }
    }
    return { {nredR, nredC}, {nblueR, nblueC} };
}
