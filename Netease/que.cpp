#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> A;
		A.push_back(n);
		for (int i = n-1; i >= 1; i--)
		{
			A.insert(A.begin(), i);
			int len = A.size();
			int val = A[len-1];
			A.erase(A.end() - 1);
			A.insert(A.begin(), val);
		}
		for (int i = 0; i < n-1; i++)
			cout << A[i] << " ";
		cout << A[n-1] << endl;
	}
	return 0;
}

