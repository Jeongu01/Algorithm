#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Fireball
{
    int r, c, m, s, d;
};

int N, M, K;
map<pair<int, int>, vector<Fireball>> arr;
vector<Fireball> fireballs;

enum
{
    UP,
    DOWN,
    RIGHT,
    LEFT
};

void check(Fireball& fireball, int dist)
{
    int speed = fireball.s % N;
    switch (dist)
    {
    case UP:
        fireball.r -= speed;
        if (fireball.r <= 0) fireball.r += N;
        break;
    case DOWN:
        fireball.r += speed;
        if (fireball.r > N) fireball.r -= N;
        break;
    case RIGHT:
        fireball.c += speed;
        if (fireball.c > N) fireball.c -= N;
        break;
    case LEFT:
        fireball.c -= speed;
        if (fireball.c <= 0) fireball.c += N;
        break;
    }
}

void moveFireball(Fireball& fireball)
{
    int dist = fireball.d;
    switch (dist)
    {
    case 0:
        check(fireball, UP);
        break;
    case 1:
        check(fireball, UP);
        check(fireball, RIGHT);
        break;
    case 2:
        check(fireball, RIGHT);
        break;
    case 3:
        check(fireball, RIGHT);
        check(fireball, DOWN);
        break;
    case 4:
        check(fireball, DOWN);
        break;
    case 5:
        check(fireball, DOWN);
        check(fireball, LEFT);
        break;
    case 6:
        check(fireball, LEFT);
        break;
    case 7:
        check(fireball, UP);
        check(fireball, LEFT);
        break;
    }

    int r = fireball.r;
    int c = fireball.c;
    int m = fireball.m;
    int s = fireball.s;
    int d = fireball.d;
    Fireball temp;
    temp.r = r;
    temp.c = c;
    temp.m = m;
    temp.s = s;
    temp.d = d;
    pair<int, int> pos = make_pair(r, c);
    arr[pos].push_back(temp);
}

void magicCmd()
{
    arr.clear();
    for (Fireball fireball : fireballs)
    {
        moveFireball(fireball);
    }

    fireballs.clear();
    for (auto iter : arr)
    {
        pair<int, int> pos = iter.first;
        int r = pos.first;
        int c = pos.second;
        vector<Fireball> info = iter.second;
        int cnt = info.size();
        if (cnt > 1)
        {
            int m_sum = 0;
            int s_sum = 0;
            bool isOdd = true;
            bool isEven = true;
            for (Fireball f : info)
            {
                m_sum += f.m;
                s_sum += f.s;
                isOdd &= f.d % 2 != 0;
                isEven &= f.d % 2 == 0;
            }
            m_sum /= 5;
            if (m_sum > 0)
            {
                Fireball temp;
                s_sum /= cnt;
                temp.r = r;
                temp.c = c;
                temp.m = m_sum;
                temp.s = s_sum;
                temp.d = 0;
                if (isOdd || isEven)
                {
                    for (int i = 0; i <= 6; i += 2)
                    {
                        temp.d = i;
                        fireballs.push_back(temp);
                    }
                }
                else
                {
                    for (int i = 1; i <= 7; i += 2)
                    {
                        temp.d = i;
                        fireballs.push_back(temp);
                    }
                }
            }
        }
        else if (cnt == 1)
        {
            Fireball temp = info[0];
            fireballs.push_back(temp);
        }
    }
}

int sumM()
{
    int ret = 0;
    for (Fireball fireball : fireballs)
    {
        ret += fireball.m;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        Fireball temp;
        temp.r = r;
        temp.c = c;
        temp.m = m;
        temp.s = s;
        temp.d = d;
        fireballs.push_back(temp);
    }

    for (int i = 0; i < K; i++)
    {
        magicCmd();
    }

    cout << sumM();

    return 0;
}