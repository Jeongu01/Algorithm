#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int board[10][10];  // (r + c, c)
vector<int> blacks[10];
vector<int> whites[10];
int N, bans = 0, wans = 0;

void placeBlack(int r, int c, int value)
{
    int half = (N / 2) + (N % 2);   // N = 5 -> 3 / N = 4 -> 2
    if (r >= half) r = N - 1 - r;
    for (int i = r, j = c; 0 <= i && i < half && 0 <= j && j < blacks[i].size(); i++, j++)
    {
        blacks[i][j] += value;
        blacks[N - 1 - i][j] += value;
    }
    for (int i = r, j = c; 0 <= i && i < half && 0 <= j && j < blacks[i].size(); i--, j--)
    {
        blacks[i][j] += value;
        blacks[N - 1 - i][j] += value;
    }
}

void placeWhite(int r, int c, int value)
{
    int Nw = N - 1;
    int half = (Nw / 2) + (Nw % 2);   // N = 5 -> 2 / N = 4 -> 2 / N = 3 -> 1
    if (r >= half) r = Nw - 1 - r;
    for (int i = r, j = c; 0 <= i && i < half && 0 <= j && j < whites[i].size(); i++, j++)
    {
        whites[i][j] += value;
        whites[Nw - i - 1][j] += value;
    }
    for (int i = r, j = c; 0 <= i && i < half && 0 <= j && j < whites[i].size(); i--, j--)
    {
        whites[i][j] += value;
        whites[Nw - i - 1][j] += value;
    }
}

void calcBlack(int r, int cnt)
{
    if (r < N)
    {
        int size = blacks[r].size();
        for (int i = 0; i < size; i++)
        {
            if (blacks[r][i] == 0)
            {
                placeBlack(r, i, 1);
                calcBlack(r + 1, cnt + 1);
                placeBlack(r, i, -1);
            }
        }
        calcBlack(r + 1, cnt);
    }
    else
        bans = max(bans, cnt);
}

void calcWhite(int r, int cnt)
{
    if (r < N - 1)
    {
        int size = whites[r].size();
        for (int i = 0; i < size; i++)
        {
            if (whites[r][i] == 0)
            {
                placeWhite(r, i, 1);
                calcWhite(r + 1, cnt + 1);
                placeWhite(r, i, -1);
            }
        }
        calcWhite(r + 1, cnt);
    }
    else
        wans = max(wans, cnt);
}

void seperateBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int input = (board[i][j] == 1) ? 0 : 1;
            if ((i + j) % 2 == 0) blacks[(i + j) / 2].push_back(input);
            else whites[(i + j) / 2].push_back(input);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int input;
            cin >> input;
            board[i][j] = input;
        }
    }

    seperateBoard();
    calcBlack(0, 0);
    calcWhite(0, 0);

    cout << bans + wans;

}