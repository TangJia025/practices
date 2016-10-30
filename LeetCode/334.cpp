#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool increasingTriplet(vector<int> &A);

int main()
{
	int B[] = {0,4,2,1,0,-1,-3};
	vector<int> A(B, B+7);

	cout << increasingTriplet(A) << endl;
	return 0;
}

bool increasingTriplet(vector<int> &A)
{
	int n  = A.size();
	if (n < 3) return false;
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		if (s.empty() || s.top() < A[i])
		{
			s.push(A[i]);
			if (s.size() >= 3) return true;
		}
		else
		{
			while (!s.empty() && s.top() >= A[i])
				s.pop();
			s.push(A[i]);
		}
	}
	return false;
}


