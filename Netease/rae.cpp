#include <iostream>
#include <math.h>

#define MIN 0.00001
using namespace std;

int main()
{
	int s;
	while (cin >> s)
	{
		int cnt = 0;
		double sq = sqrt(s);
		int n = (int)sq;
		if (sq - n < MIN)
		{
			cnt += 4;
			n--;
		}
		int m = 0;
        for (int i = 1; i <= n; i++)
		{
			int a = s - i*i;
			double sq2 = sqrt(a);
			if (sq2 - (int)sq2 < MIN)
				m++;
		}
		m *= 4;
		cnt += m;
		cout << cnt << endl;
	}
	return 0;
}

