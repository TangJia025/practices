#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> A;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			A.push_back(a);
		}
		sort(A.begin(), A.end());
		vector<string> B;
		for (int i = 0; i < m; i++)
		{
			string s;
			cin >> s;
			B.push_back(s);
		}
		map<string, int> C;
		for (int i = 0; i < B.size(); i++)
			C[B[i]]++;
		vector<int> D;
		map<string, int>::iterator iter = C.begin();
        for (; iter != C.end(); iter++)
			D.push_back(iter->second);

		sort(D.begin(), D.end());
		int ma, mi;
		ma = mi = 0;
		int len = D.size();
		for (int i = 0; i < len; i++)
		{
			mi += A[i] * D[len-1-i];
		}
		for (int i = n-1, j = len-1; j >= 0; i--, j--)
		{
			ma += A[i] * D[j];
		}
		cout << mi << " " << ma << endl;
	}
	return 0;
}


