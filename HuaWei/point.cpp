#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void Move(string s1, int &x, int &y);

int main()
{
	string s;
	while (cin >> s)
	{
		int x, y;
		x = y = 0;
		int i = 0;
		while (i < s.size())
		{
			int j = s.find_first_of(';', i);
			string s1 = s.substr(i, j-i);
			Move(s1, x, y);
			i = j+1;
		}
        cout << x << "," << y << endl;
	}
	return 0;
}

void Move(string s1, int &x, int &y)
{
	if ((s1.size() == 3 || s1.size() == 2) && (s1[0] == 'A' || s1[0] == 'D' || s1[0] == 'W' || s1[0] == 'S'))
	{
		string s2 = s1.substr(1);
		int a = 0;
		for (int i = 0; i < s2.size(); i++)
		{
			if (s2[i] >= '0' && s2[i] <= '9')
				a = 10 * a + (s2[i] - '0');
			else
				return;
		}
		if (s1[0] == 'A') 
			x -= a;
		else if (s1[0] == 'D')
			x += a;
		else if (s1[0] == 'W')
			y += a;
		else 
			y -= a;
	}
}

