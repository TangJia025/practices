#include <iostream>

using namespace std;

int main()
{
	long int n;
	while (cin >> n)
	{
		long int s = 0;
		for (long int i = 1; i <= n; i++)
		{
			if (i % 2 == 1)
			{
				s += i;
			}
			else
			{
				long a = i;
				while (a % 2 == 0) a /= 2;
				s += a;
			}
		}
		cout << s << endl;
	}
	return 0;
}

