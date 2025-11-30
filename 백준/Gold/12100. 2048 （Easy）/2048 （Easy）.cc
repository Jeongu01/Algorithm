#include <iostream>
#include <cstring>
using namespace std;

int N, ans;
int board[20][20];
int maxNum[11];

void up(int[][20], int);
void down(int[][20], int);
void right(int[][20], int);
void left(int[][20], int);

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
            cin >> board[i][j];
        }
    }
    up(board, 0);
    down(board, 0);
    right(board, 0);
    left(board, 0);
    cout << ans;
}

void up(int arr[][20], int depth)
{
    int num = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            num = max(num, arr[i][j]);

    if (depth == 5)
    {
        if (num > ans) ans = num;
        for (int i = 5; i >= 0; i--)
        {
            maxNum[i] = num;
            num /= 2;
        }
        return;
    }
    if (num <= maxNum[depth]) return;

    int temp[20][20];
    memset(temp, 0, sizeof(int) * 20 * 20);

    bool isChanged = false;
    bool isSummed = false;
    for (int c = 0; c < N; c++)
    {
        int prev = 0, idx = 0;
        for (int r = 0; r < N; r++)
        {
            if (arr[r][c] == 0) continue;
            if (prev == 0)
            {
                prev = arr[r][c];
            }
            else if (prev == arr[r][c])
            {
                temp[idx][c] = prev + prev;
                idx++;
                prev = 0;
                isSummed = true;
            }
            else
            {
                temp[idx][c] = prev;
                idx++;
                prev = arr[r][c];
            }
        }
        if (prev != 0) temp[idx][c] = prev;
        if (isChanged == true) continue;
        for (int r = 0; r < N; r++)
        {
            if (temp[r][c] != arr[r][c]) isChanged = true;
        }
    }

    if (isChanged == false)
    {
        if (num > ans) ans = num;
        for (int i = 5; i >= 0; i--)
        {
            maxNum[i] = num;
            num /= 2;
        }
        return;
    }

    if (isSummed == true) up(temp, depth + 1);
    down(temp, depth + 1);
    right(temp, depth + 1);
    left(temp, depth + 1);
}

void down(int arr[][20], int depth)
{
    int num = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            num = max(num, arr[i][j]);

    if (depth == 5)
    {
        if (num > ans) ans = num;
        for (int i = 5; i >= 0; i--)
        {
            maxNum[i] = num;
            num /= 2;
        }
        return;
    }
    if (num <= maxNum[depth]) return;

    int temp[20][20];
    memset(temp, 0, sizeof(int) * 20 * 20);

    bool isChanged = false;
    bool isSummed = false;
    for (int c = 0; c < N; c++)
    {
        int prev = 0, idx = N - 1;
        for (int r = N - 1; r >= 0; r--)
        {
            if (arr[r][c] == 0) continue;
            if (prev == 0)
            {
                prev = arr[r][c];
            }
            else if (prev == arr[r][c])
            {
                temp[idx][c] = prev + prev;
                idx--;
                prev = 0;
                isSummed = true;
            }
            else
            {
                temp[idx][c] = prev;
                idx--;
                prev = arr[r][c];
            }
        }
        if (prev != 0) temp[idx][c] = prev;
        if (isChanged == true) continue;
        for (int r = 0; r < N; r++)
        {
            if (temp[r][c] != arr[r][c]) isChanged = true;
        }
    }

    if (isChanged == false)
    {
        if (num > ans) ans = num;
        for (int i = 5; i >= 0; i--)
        {
            maxNum[i] = num;
            num /= 2;
        }
        return;
    }

    up(temp, depth + 1);
    if (isSummed == true) down(temp, depth + 1);
    right(temp, depth + 1);
    left(temp, depth + 1);
}

void right(int arr[][20], int depth)
{
    int num = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            num = max(num, arr[i][j]);

    if (depth == 5)
    {
        if (num > ans) ans = num;
        for (int i = 5; i >= 0; i--)
        {
            maxNum[i] = num;
            num /= 2;
        }
        return;
    }
    if (num <= maxNum[depth]) return;

    int temp[20][20];
    memset(temp, 0, sizeof(int) * 20 * 20);

    bool isChanged = false;
    bool isSummed = false;
    for (int r = 0; r < N; r++)
    {
        int prev = 0, idx = N - 1;
        for (int c = N - 1; c >= 0; c--)
        {
            if (arr[r][c] == 0) continue;
            if (prev == 0)
            {
                prev = arr[r][c];
            }
            else if (prev == arr[r][c])
            {
                temp[r][idx] = prev + prev;
                idx--;
                prev = 0;
                isSummed = true;
            }
            else
            {
                temp[r][idx] = prev;
                idx--;
                prev = arr[r][c];
            }
        }
        if (prev != 0) temp[r][idx] = prev;
        if (isChanged == true) continue;
        for (int c = 0; c < N; c++)
        {
            if (temp[r][c] != arr[r][c]) isChanged = true;
        }
    }

    if (isChanged == false)
    {
        if (num > ans) ans = num;
        for (int i = 5; i >= 0; i--)
        {
            maxNum[i] = num;
            num /= 2;
        }
        return;
    }

    up(temp, depth + 1);
    down(temp, depth + 1);
    if (isSummed == true) right(temp, depth + 1);
    left(temp, depth + 1);
}

void left(int arr[][20], int depth)
{
    int num = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            num = max(num, arr[i][j]);

    if (depth == 5)
    {
        if (num > ans) ans = num;
        for (int i = 5; i >= 0; i--)
        {
            maxNum[i] = num;
            num /= 2;
        }
        return;
    }
    if (num <= maxNum[depth]) return;

    int temp[20][20];
    memset(temp, 0, sizeof(int) * 20 * 20);

    bool isChanged = false;
    bool isSummed = false;
    for (int r = 0; r < N; r++)
    {
        int prev = 0, idx = 0;
        for (int c = 0; c < N; c++)
        {
            if (arr[r][c] == 0) continue;
            if (prev == 0)
            {
                prev = arr[r][c];
            }
            else if (prev == arr[r][c])
            {
                temp[r][idx] = prev + prev;
                idx++;
                prev = 0;
                isSummed = true;
            }
            else
            {
                temp[r][idx] = prev;
                idx++;
                prev = arr[r][c];
            }
        }
        if (prev != 0) temp[r][idx] = prev;
        if (isChanged == true) continue;
        for (int c = 0; c < N; c++)
        {
            if (temp[r][c] != arr[r][c]) isChanged = true;
        }
    }

    if (isChanged == false)
    {
        if (num > ans) ans = num;
        for (int i = 5; i >= 0; i--)
        {
            maxNum[i] = num;
            num /= 2;
        }
        return;
    }

    up(temp, depth + 1);
    down(temp, depth + 1);
    right(temp, depth + 1);
    if (isSummed == true) left(temp, depth + 1);
}
