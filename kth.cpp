#include <iostream>

using namespace std;

int main()
{
	int x, k;
	while (cin >> x >> k)
	{
		int y = x;
		int n = 0;
		while (y)
		{
			n++;
			y = y >> 1;
		}
		int flag[n];
		for (int i = 0; i < n; i++)
		{
			if (x & (1 << i))
				flag[i] = 1;
			else
				flag[i] = 0;
		}
		int i = 0;
		int rec = 0;
		for (; i < n; i++)
		{
			if (flag[i] == 0)
			{
				rec++;
				if (rec == k)
				{
					// 取得 A[10] 前i位的反码
				}
			}
		}
	}
	return 0;
}


