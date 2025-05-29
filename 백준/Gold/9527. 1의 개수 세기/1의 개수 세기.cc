#include <iostream>
using namespace std;

using ull = long long;
ull A, B, sum;
ull arr[65];

ull countOne(ull num, int bitCnt)
{
	ull bits = 0, bit = 1, ret = 0, f = 1;
	f <<= bitCnt - 1;
	num -= f;
	if (num >= 0) ret += num + 1;

	int i = 1;
	while (num >= bit)
	{
		ull temp = (num >> i) << (i - 1);
		ret += temp;
		if ((bit & num) != 0) ret += bits + 1;
		bits = bits | (bit & num);
		i++;
		bit = bit << 1;
	}
	return ret;
}


int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int Abits = 1, Bbits = 1;
   ull A, B, bit = 1;
   for (int i = 1; i < 65; i++)
   {
	   arr[i] = sum + bit;
	   bit <<= 1;
	   sum += arr[i];
   }

   cin >> A >> B;

   ull temp = A;
   while (temp >>= 1) { Abits++; }
   temp = B;
   while (temp >>= 1) { Bbits++; }

   for (int i = Abits; i < Bbits; i++)
   {
	   sum += arr[i];
   }
   sum -= countOne(A - 1, Abits);
   sum += countOne(B, Bbits);
   cout << sum;
}