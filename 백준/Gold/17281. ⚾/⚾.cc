#include <iostream>
using namespace std;

int N, ans;
bool field[4];
int inning[50][10];

void play(int* order)
{
    int cur = 0, pnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int i = 1; i < 4; i++) field[i] = false;
        int out_cnt = 0;
        while (out_cnt < 3)
        {
            int res = inning[i][order[cur]];
            switch (res)
            {
            case 0:
                out_cnt++;
                break;
            case 1:
                pnt += field[3];
                field[3] = field[2];
                field[2] = field[1];
                field[1] = true;
                break;
            case 2:
                pnt += field[3] + field[2];
                field[3] = field[1];
                field[2] = true;
                field[1] = false;
                break;
            case 3:
                pnt += field[3] + field[2] + field[1];
                field[3] = true;
                field[2] = false;
                field[1] = false;
                break;
            case 4:
                pnt += field[3] + field[2] + field[1] + 1;
                for (int i = 1; i < 4; i++) field[i] = false;
                break;
            }
            cur = (cur + 1) % 9;
        }
    }
    ans = max(ans, pnt);
}

void changeOrder(int* order, int o)
{
    if (o == 10)
    {
        play(order);
        return;
    }
    for (int i = 0; i < 9; i++)
    {
        if (order[i] != 0) continue;
        order[i] = o;
        changeOrder(order, o + 1);
        order[i] = 0;
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
        for (int j = 1; j < 10; j++)
        {
            cin >> inning[i][j];
        }
    }
    int order[9];
    for (int i = 0; i < 9; i++) order[i] = 0;
    order[3] = 1;
    changeOrder(order, 2);
    cout << ans;
}