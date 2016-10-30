#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int> A;
		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			A.push_back(a);
		}
		int pre[N], cur[N];
		int res, id;
		pre[0] = -1;
		res = cur[0] = 1;
		id = 0;
		for (int i = 1; i < N; i++)
		{
			cur[i] = 0;
			int idx = -1;
			for (int j = i-1; j >= 0; j--)
			{
				if (A[i] > A[j] && cur[i] < cur[j])
				{
					cur[i] = cur[j];
					idx = j;
				}
			}
			cur[i]++;
			pre[i] = idx;
			if (res < cur[i])
		    {
				res = cur[i];
				id = i;
			}
		}
		int k = id;
		vector<int> result;
		while (k != -1)
		{
			result.push_back(A[k]);
			k = pre[k];
		}
		reverse(result.begin(), result.end());
		int n = result.size();
		for (int i = 0; i < n-1; i++)
			cout << result[i] << " ";
		cout << result[n-1] << endl;
	}
	return 0;
}

