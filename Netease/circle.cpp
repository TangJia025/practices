#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int s;
	while (cin >> s)
	{
		double a = sqrt(s);
		int m, cnt;
		if (a - (int)a == 0)
		{
			m = (int)a - 1;
			cnt = 4;
		}
		else
		{
			m = (int)a;
			cnt = 0;
		}
		for (int i = 1; i <= m; i++)
		{
			int b = s - i*i;
			double c = sqrt(b);
			if (c - (int)c == 0)
			{
				cnt += 4;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}


