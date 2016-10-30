#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int A[1000];
	for (int i = 0; i < 1000; i++) A[i] = 1;
	vector<int> B;
	A[0] = A[1] = 0;
	for (int i = 2; i < 1000; i++)
	{
		if (A[i] == 0) continue;
		B.push_back(i);
		for (int j = 2*i; j < 1000; j += i)
		{
			A[j] = 0;
		}
	}
	int m;
	while (cin >> m)
	{
		int cnt = 0;
		if (m % 2 == 0 && A[m/2] == 1) cnt++;
		int i, j;
		i = 0, j = B.size()-1;
		while (i < j)
		{
			if (B[i]+B[j] == m)
			{
				cnt++;
				i++;
				j--;
			}
			else if (B[i]+B[j] > m)
				j--;
			else
				i++;
		}
		cout << cnt << endl;
	}
	return 0;
}

	
