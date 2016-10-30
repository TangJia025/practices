#include <iostream>
#include <vector>

using namespace std;

int Count(vector<int> A);

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> A;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			A.push_back(a);
		}
		int t = Count(A);
		cout << t << endl;
	}
	return 0;
}

int Count(vector<int> A)
{
	int n = A.size();
	int res = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (j == i+1)
				res++;
			else
			{
				bool flag = true;
				for (int k = i+1; k < j; k++)
				{
					if (A[k] > A[i] || A[k] > A[j])
					{
						flag = false;
						break;
					}
				}
				if (flag)
                {
					res++;
					continue;
				}
                flag = true;
				for (int k = 0; k < i; k++)
				{
					if (A[k] > A[i] || A[k] > A[j])
					{
						flag = false;
						break;
					}
				}
				for (int k = j+1; k < n; k++)
				{
					if (A[k] > A[i] || A[k] > A[j])
					{
						flag = false;
						break;
					}
				}
				if (flag)
					res++;
			}
		}
	}
	return res;
}


