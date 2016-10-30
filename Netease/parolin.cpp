#include <iostream>
#include <string>

using namespace std;

bool isParolin(string s);

int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		int count = 0;
		int la = A.size();
		for (int i  = 1; i <= la-1; i++)
		{
			string s = A.substr(0, i) + B + A.substr(i);
			if (isParolin(s))
				count++;
		}
		string s = B + A;
		if (isParolin(s)) count++;
		s = A + B;
		if (isParolin(s)) count++;
		cout << count << endl;
	}
	return 0;
}

bool isParolin(string s)
{
	int len = s.size();
	for (int i = 0; i < len / 2; i++)
		if (s[i] != s[len-1-i])
			return false;
	return true;
}

