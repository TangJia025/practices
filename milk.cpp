#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

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
		int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % n != 0)
		{
		    cout << "-1" << endl;
			continue;
		}
		int avg = sum / n;
		int cnt = 0;
		sort(A.begin(), A.end());
		while (A[n-1] - A[0] >= 4)
		{
			while (A[n-1] - A[0] >= 4)
			{
				A[0] += 2;
				A[n-1] -= 2;
				cnt++;
			}
			sort(A.begin(), A.end());
		}
		if (A[0] == A[n-1])
		{
			cout << cnt << endl;
		}
		else
			cout << "-1" << endl;
	}
	return 0;
}


		
