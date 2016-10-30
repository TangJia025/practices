#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> largestDivisible(vector<int> &A);

int main()
{
	int B[6] = {1,2,4,8,9,72};
	vector<int> A(B, B+6);
	vector<int> C = largestDivisible(A);
	for (int i = 0; i < C.size(); i++)
		cout << C[i] << " ";
	cout << endl;
	return 0;
}

vector<int> largestDivisible(vector<int> &A)
{
	int n = A.size();
	int pre[n], cur[n];
	pre[0] = -1;
	cur[0] = 1;
	for (int i = 1; i < n; i++)
	{
		int cu = 0, id = -1;
		for (int j = i-1; j >= 0; j--)
		{
			if (A[i] % A[j] == 0)
			{
				if (cu < cur[j])
				{
					cu = cur[j];
					id = j;
				}
			}
		}
		cur[i] = cu + 1;
		pre[i] = id;
	}
	int res = 1, idx = 0;
	for (int i = 0; i < n; i++)
	{
		if (res < cur[i])
		{
			res = cur[i];
			idx = i;
		}
	}
	vector<int> result;
	int j = idx;
	while (j != -1)
	{
		result.push_back(A[j]);
		j = pre[j];
	}
	reverse(result.begin(), result.end());
	return result;
}


