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
		int cur[N];
		cur[0] = 1;
		int res = 1;
		for (int i = 1; i < N; i++)
		{
			cur[i] = 0;
			for (int j = i-1; j >= 0; j--)
			{
				if (A[i] > A[j] && cur[i] < cur[j])
					cur[i] = cur[j];
			}
			cur[i]++;
			res = max(res, cur[i]);
		}
		cout << res << endl;
	}
	return 0;
}


