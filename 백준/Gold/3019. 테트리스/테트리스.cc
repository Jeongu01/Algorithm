#include <iostream>
#include <vector>
using namespace std;

int arr[101];
vector<int> blocks[8][5];
int C, P, answer = 0;

void case1()
{
	// 0 degree
	answer += C;

	// 90 degree
	for (int i = 1; i + 3 <= C; i++)
	{
		int s = arr[i];
		bool b = true;
		for (int j = 1; j < 4; j++)
		{
			b &= arr[i] == arr[i + j];
		}
		if (b) answer++;
	}
}

void case2()
{
	// 0 degree
	for (int i = 1; i + 1 <= C; i++)
	{
		bool b = arr[i] == arr[i + 1];
		if (b) answer++;
	}
}

void case3()
{
	// 0 degree
	for (int i = 1; i + 2 <= C; i++)
	{
		int s = arr[i];
		bool b = s == arr[i + 1];
		b &= s + 1 == arr[i + 2];
		if (b) answer++;
	}

	// 90 degree
	for (int i = 1; i + 1 <= C; i++)
	{
		int s = arr[i];
		bool b = s == arr[i + 1] + 1;
		if (b) answer++;
	}
}

void case4()
{
	// 0 degree
	for (int i = 1; i + 2 <= C; i++)
	{
		int s = arr[i];
		bool b = s == arr[i + 1] + 1;
		b &= s == arr[i + 2] + 1;
		if (b) answer++;
	}

	// 90 degree
	for (int i = 1; i + 1 <= C; i++)
	{
		int s = arr[i];
		bool b = s + 1 == arr[i + 1];
		if (b) answer++;
	}
}


void case5()
{
	// 0 degree
	for (int i = 1; i + 2 <= C; i++)
	{
		int s = arr[i];
		bool b = s == arr[i + 1];
		b &= s == arr[i + 2];
		if (b) answer++;
	}

	// 90 degree
	for (int i = 1; i + 1 <= C; i++)
	{
		int s = arr[i];
		bool b = s == arr[i + 1] + 1;
		if (b) answer++;
	}

	// 180 degree
	for (int i = 1; i + 2 <= C; i++)
	{
		int s = arr[i];
		bool b = s == arr[i + 1] + 1;
		b &= s == arr[i + 2];
		if (b) answer++;
	}

	// 270 degree
	for (int i = 1; i + 1 <= C; i++)
	{
		int s = arr[i];
		bool b = s + 1 == arr[i + 1];
		if (b) answer++;
	}
}

void case6()
{
	// 0 degree
	for (int i = 1; i + 2 <= C; i++)
	{
		int s = arr[i];
		bool b = s == arr[i + 1];
		b &= s == arr[i + 2];
		if (b) answer++;
	}

	// 90 degree
	for (int i = 1; i + 1 <= C; i++)
	{
		int s = arr[i];
		bool b = s == arr[i + 1] + 2;
		if (b) answer++;
	}

	// 180 degree
	for (int i = 1; i + 2 <= C; i++)
	{
		int s = arr[i];
		bool b = s + 1 == arr[i + 1];
		b &= s + 1 == arr[i + 2];
		if (b) answer++;
	}

	// 270 degree
	for (int i = 1; i + 1 <= C; i++)
	{
		int s = arr[i];
		bool b = s == arr[i + 1];
		if (b) answer++;
	}
}

void case7()
{
	// 0 degree
	for (int i = 1; i + 2 <= C; i++)
	{
		int s = arr[i];
		bool b = s == arr[i + 1];
		b &= s == arr[i + 2];
		if (b) answer++;
	}

	// 90 degree
	for (int i = 1; i + 1 <= C; i++)
	{
		int s = arr[i];
		bool b = s + 2 == arr[i + 1];
		if (b) answer++;
	}

	// 180 degree
	for (int i = 1; i + 2 <= C; i++)
	{
		int s = arr[i];
		bool b = s == arr[i + 1];
		b &= s == arr[i + 2] + 1;
		if (b) answer++;
	}

	// 270 degree
	for (int i = 1; i + 1 <= C; i++)
	{
		int s = arr[i];
		bool b = s == arr[i + 1];
		if (b) answer++;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> C >> P;

	for (int i = 1; i <= C; i++)
	{
		cin >> arr[i];
	}

	switch (P)
	{
	case 1:
		case1();
		break;
	case 2:
		case2();
		break;
	case 3:
		case3();
		break;
	case 4:
		case4();
		break;
	case 5:
		case5();
		break;
	case 6:
		case6();
		break;
	case 7:
		case7();
		break;
	}

	cout << answer;

	return 0;
}