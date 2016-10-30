#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int n;
vector<string> svec;

int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			svec.push_back(s);
		}
		int A[10];
		for (int i = 0; i < 10; i++) A[i] = 0;
		for (int i = 0; i < n; i++)
		{
			int len = svec[i].size();
			for (int j = 0; j < len; j++)
			{
				A[svec[i][j] - 'A'] += (int)pow(10.0, len - 1 - j);
			}
		}
		int res = 0;
		sort(A, A + 10);
		for (int i = 0; i < 10; i++)
			res += i * A[i];
		cout << "max num is " << res << endl;
		svec.clear();
	}
	return 0;
}


