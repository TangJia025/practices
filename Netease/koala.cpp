#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> A;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			A.push_back(str);
		}
		bool Lex = true;
		bool Len = true;
		for (int i = 0; i < n-1; i++)
			if (A[i].compare(A[i+1]) > 0)
			{
				Lex = false;
				break;
			}
		for (int i = 0; i < n-1; i++)
			if (A[i].size() > A[i+1].size())
			{
				Len = false;
				break;
			}
		if (Lex && Len)
			cout << "both" << endl;
		else if (Lex)
			cout << "lexi" << endl;
		else if (Len)
			cout << "lenght" << endl;
		else
			cout << "none" << endl;
	}
	return 0;
}


