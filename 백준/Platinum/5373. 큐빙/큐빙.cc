#include <iostream>
using namespace std;

#define U 0
#define D 1
#define F 2
#define B 3
#define L 4
#define R 5

char cube[6][3][3];
void setCube(int, char);
void turnUp(char);
void turnDown(char);
void turnFront(char);
void turnBack(char);
void turnLeft(char);
void turnRight(char);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		setCube(U, 'w');
		setCube(D, 'y');
		setCube(F, 'r');
		setCube(B, 'o');
		setCube(L, 'g');
		setCube(R, 'b');
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			char side, dir;
			cin >> side >> dir;
			switch (side)
			{
			case 'U':
				turnUp(dir);
				break;
			case 'D':
				turnDown(dir);
				break;
			case 'F':
				turnFront(dir);
				break;
			case 'B':
				turnBack(dir);
				break;
			case 'L':
				turnLeft(dir);
				break;
			case 'R':
				turnRight(dir);
				break;
			}
		}
		for (int k = 0; k < 1; k++)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << cube[k][i][j];
				}
				cout << "\n";
			}
		}
	}
}

void setCube(int side, char color)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cube[side][i][j] = color;
		}
	}
}

void turnMainSide(int side, char dir)
{
	char temp[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = cube[side][i][j];
		}
	}
	if (dir == '+')
	{
		cube[side][0][0] = temp[2][0];
		cube[side][0][1] = temp[1][0];
		cube[side][0][2] = temp[0][0];
		cube[side][1][0] = temp[2][1];
		cube[side][1][1] = temp[1][1];
		cube[side][1][2] = temp[0][1];
		cube[side][2][0] = temp[2][2];
		cube[side][2][1] = temp[1][2];
		cube[side][2][2] = temp[0][2];
	}
	else
	{
		cube[side][0][0] = temp[0][2];
		cube[side][0][1] = temp[1][2];
		cube[side][0][2] = temp[2][2];
		cube[side][1][0] = temp[0][1];
		cube[side][1][1] = temp[1][1];
		cube[side][1][2] = temp[2][1];
		cube[side][2][0] = temp[0][0];
		cube[side][2][1] = temp[1][0];
		cube[side][2][2] = temp[2][0];
	}
}

void turnUp(char dir)
{
	char temp[3];
	turnMainSide(U, dir);
	if (dir == '+')
	{
		temp[0] = cube[F][0][0];
		temp[1] = cube[F][0][1];
		temp[2] = cube[F][0][2];

		cube[F][0][0] = cube[R][0][0];
		cube[F][0][1] = cube[R][0][1];
		cube[F][0][2] = cube[R][0][2];

		cube[R][0][0] = cube[B][0][0];
		cube[R][0][1] = cube[B][0][1];
		cube[R][0][2] = cube[B][0][2];

		cube[B][0][0] = cube[L][0][0];
		cube[B][0][1] = cube[L][0][1];
		cube[B][0][2] = cube[L][0][2];

		cube[L][0][0] = temp[0];
		cube[L][0][1] = temp[1];
		cube[L][0][2] = temp[2];
	}
	else
	{
		temp[0] = cube[F][0][0];
		temp[1] = cube[F][0][1];
		temp[2] = cube[F][0][2];

		cube[F][0][0] = cube[L][0][0];
		cube[F][0][1] = cube[L][0][1];
		cube[F][0][2] = cube[L][0][2];

		cube[L][0][0] = cube[B][0][0];
		cube[L][0][1] = cube[B][0][1];
		cube[L][0][2] = cube[B][0][2];

		cube[B][0][0] = cube[R][0][0];
		cube[B][0][1] = cube[R][0][1];
		cube[B][0][2] = cube[R][0][2];

		cube[R][0][0] = temp[0];
		cube[R][0][1] = temp[1];
		cube[R][0][2] = temp[2];
	}
}

void turnDown(char dir)
{
	char temp[3];
	turnMainSide(D, dir);
	if (dir == '+')
	{
		temp[0] = cube[F][2][0];
		temp[1] = cube[F][2][1];
		temp[2] = cube[F][2][2];

		cube[F][2][0] = cube[L][2][0];
		cube[F][2][1] = cube[L][2][1];
		cube[F][2][2] = cube[L][2][2];

		cube[L][2][0] = cube[B][2][0];
		cube[L][2][1] = cube[B][2][1];
		cube[L][2][2] = cube[B][2][2];

		cube[B][2][0] = cube[R][2][0];
		cube[B][2][1] = cube[R][2][1];
		cube[B][2][2] = cube[R][2][2];

		cube[R][2][0] = temp[0];
		cube[R][2][1] = temp[1];
		cube[R][2][2] = temp[2];
	}
	else
	{
		temp[0] = cube[F][2][0];
		temp[1] = cube[F][2][1];
		temp[2] = cube[F][2][2];

		cube[F][2][0] = cube[R][2][0];
		cube[F][2][1] = cube[R][2][1];
		cube[F][2][2] = cube[R][2][2];

		cube[R][2][0] = cube[B][2][0];
		cube[R][2][1] = cube[B][2][1];
		cube[R][2][2] = cube[B][2][2];

		cube[B][2][0] = cube[L][2][0];
		cube[B][2][1] = cube[L][2][1];
		cube[B][2][2] = cube[L][2][2];

		cube[L][2][0] = temp[0];
		cube[L][2][1] = temp[1];
		cube[L][2][2] = temp[2];
	}
}

void turnFront(char dir)
{
	char temp[3];
	turnMainSide(F, dir);
	if (dir == '+')
	{
		temp[0] = cube[U][2][0];
		temp[1] = cube[U][2][1];
		temp[2] = cube[U][2][2];

		cube[U][2][0] = cube[L][2][2];
		cube[U][2][1] = cube[L][1][2];
		cube[U][2][2] = cube[L][0][2];

		cube[L][0][2] = cube[D][2][2];
		cube[L][1][2] = cube[D][2][1];
		cube[L][2][2] = cube[D][2][0];

		cube[D][2][0] = cube[R][0][0];
		cube[D][2][1] = cube[R][1][0];
		cube[D][2][2] = cube[R][2][0];

		cube[R][0][0] = temp[0];
		cube[R][1][0] = temp[1];
		cube[R][2][0] = temp[2];
	}
	else
	{
		temp[0] = cube[U][2][0];
		temp[1] = cube[U][2][1];
		temp[2] = cube[U][2][2];

		cube[U][2][0] = cube[R][0][0];
		cube[U][2][1] = cube[R][1][0];
		cube[U][2][2] = cube[R][2][0];

		cube[R][0][0] = cube[D][2][0];
		cube[R][1][0] = cube[D][2][1];
		cube[R][2][0] = cube[D][2][2];

		cube[D][2][0] = cube[L][2][2];
		cube[D][2][1] = cube[L][1][2];
		cube[D][2][2] = cube[L][0][2];

		cube[L][2][2] = temp[0];
		cube[L][1][2] = temp[1];
		cube[L][0][2] = temp[2];
	}
}

void turnBack(char dir)
{
	char temp[3];
	turnMainSide(B, dir);
	if (dir == '+')
	{
		temp[0] = cube[U][0][0];
		temp[1] = cube[U][0][1];
		temp[2] = cube[U][0][2];

		cube[U][0][0] = cube[R][0][2];
		cube[U][0][1] = cube[R][1][2];
		cube[U][0][2] = cube[R][2][2];

		cube[R][0][2] = cube[D][0][0];
		cube[R][1][2] = cube[D][0][1];
		cube[R][2][2] = cube[D][0][2];

		cube[D][0][0] = cube[L][2][0];
		cube[D][0][1] = cube[L][1][0];
		cube[D][0][2] = cube[L][0][0];

		cube[L][2][0] = temp[0];
		cube[L][1][0] = temp[1];
		cube[L][0][0] = temp[2];
	}
	else
	{
		temp[0] = cube[U][0][0];
		temp[1] = cube[U][0][1];
		temp[2] = cube[U][0][2];

		cube[U][0][0] = cube[L][2][0];
		cube[U][0][1] = cube[L][1][0];
		cube[U][0][2] = cube[L][0][0];

		cube[L][2][0] = cube[D][0][0];
		cube[L][1][0] = cube[D][0][1];
		cube[L][0][0] = cube[D][0][2];

		cube[D][0][0] = cube[R][0][2];
		cube[D][0][1] = cube[R][1][2];
		cube[D][0][2] = cube[R][2][2];

		cube[R][0][2] = temp[0];
		cube[R][1][2] = temp[1];
		cube[R][2][2] = temp[2];
	}
}

void turnLeft(char dir)
{
	char temp[3];
	turnMainSide(L, dir);
	if (dir == '+')
	{
		temp[0] = cube[U][0][0];
		temp[1] = cube[U][1][0];
		temp[2] = cube[U][2][0];

		cube[U][0][0] = cube[B][2][2];
		cube[U][1][0] = cube[B][1][2];
		cube[U][2][0] = cube[B][0][2];

		cube[B][2][2] = cube[D][2][2];
		cube[B][1][2] = cube[D][1][2];
		cube[B][0][2] = cube[D][0][2];

		cube[D][2][2] = cube[F][0][0];
		cube[D][1][2] = cube[F][1][0];
		cube[D][0][2] = cube[F][2][0];

		cube[F][0][0] = temp[0];
		cube[F][1][0] = temp[1];
		cube[F][2][0] = temp[2];
	}
	else
	{
		temp[0] = cube[U][0][0];
		temp[1] = cube[U][1][0];
		temp[2] = cube[U][2][0];

		cube[U][0][0] = cube[F][0][0];
		cube[U][1][0] = cube[F][1][0];
		cube[U][2][0] = cube[F][2][0];

		cube[F][0][0] = cube[D][2][2];
		cube[F][1][0] = cube[D][1][2];
		cube[F][2][0] = cube[D][0][2];

		cube[D][2][2] = cube[B][2][2];
		cube[D][1][2] = cube[B][1][2];
		cube[D][0][2] = cube[B][0][2];

		cube[B][2][2] = temp[0];
		cube[B][1][2] = temp[1];
		cube[B][0][2] = temp[2];
	}
}

void turnRight(char dir)
{
	char temp[3];
	turnMainSide(R, dir);
	if (dir == '+')
	{
		temp[0] = cube[U][0][2];
		temp[1] = cube[U][1][2];
		temp[2] = cube[U][2][2];

		cube[U][0][2] = cube[F][0][2];
		cube[U][1][2] = cube[F][1][2];
		cube[U][2][2] = cube[F][2][2];

		cube[F][0][2] = cube[D][2][0];
		cube[F][1][2] = cube[D][1][0];
		cube[F][2][2] = cube[D][0][0];

		cube[D][2][0] = cube[B][2][0];
		cube[D][1][0] = cube[B][1][0];
		cube[D][0][0] = cube[B][0][0];

		cube[B][2][0] = temp[0];
		cube[B][1][0] = temp[1];
		cube[B][0][0] = temp[2];
	}
	else
	{
		temp[0] = cube[U][0][2];
		temp[1] = cube[U][1][2];
		temp[2] = cube[U][2][2];

		cube[U][0][2] = cube[B][2][0];
		cube[U][1][2] = cube[B][1][0];
		cube[U][2][2] = cube[B][0][0];

		cube[B][2][0] = cube[D][2][0];
		cube[B][1][0] = cube[D][1][0];
		cube[B][0][0] = cube[D][0][0];

		cube[D][2][0] = cube[F][0][2];
		cube[D][1][0] = cube[F][1][2];
		cube[D][0][0] = cube[F][2][2];

		cube[F][0][2] = temp[0];
		cube[F][1][2] = temp[1];
		cube[F][2][2] = temp[2];
	}
}