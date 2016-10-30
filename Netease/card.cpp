#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
	    int n, k;
	    cin >> n >> k;
	    vector<int> A(2*n, 0);
	    for (int i = 0; i < 2*n; i++)
		    cin >> A[i];
	    vector<int> B(2*n, 0);
		while (k--)
	    {
		    int j = 0;
		    for (int i = 0; i < n; i++, j+=2)
		    {
			    B[j] = A[i];
			    B[j+1] = A[i+n];
		    }  
			A = B;
     	}
		for (int i = 0; i < 2*n - 1; i++)
			cout << A[i] << " ";
		cout << A[2*n-1] << endl;
	}
	return 0;
}

