#include <stdlib.h>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		if (s.size() < 8)
		{
			int a = atoi(c_str(s));
			int b = (int)sqrt(a);
			cout << b << endl;
			continue;
		}
		if (s.size() % 2 == 1)
		{
			int a = s[0] - '0';
			int l = (s.size() - 1) / 2;
			int i = (int)sqrt(a);
			for (int j = 0; j < l; j++)
				i *= 10;
			cout << i << endl;
		}
		else
		{
			int a = 10 * (s[0] - '0') + s[1] - s[0];
			int l = (s.size() - 2) / 2;
			int i = (int)sqrt(a);
			for (int j = 0; j < l; j++)
				i *= 10;
			cout << i << endl;
		}
	}
	return 0;
}

		

