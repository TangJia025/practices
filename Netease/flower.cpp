#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		for (int i = m; i <= n; i++)
		{
			int a = i;
			int s = 0;
			while (a)
			{
				int b = a % 10;
				s += pow(b, 3);
				a /= 10;
			}
			if (i == s)
				cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}

