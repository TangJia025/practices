#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> A;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());
	int cnt = 0;
	int i = 0;
	while (i < n)
	{
		if (i+2 < n)
		{
	    	if (A[i+1] - A[i] > 20)
	    	{
		    	cnt += 2;
		    	i++;
	    	}
	    	else if (A[i+1] - A[i] > 10)
	    	{
		    	cnt += 1;
		    	i += 2;
	    	}
	    	else
	    	{
		    	if (A[i+2] - A[i+1] > 10)
		    	{
			    	cnt += 1;
			    	i += 2;
		    	}
		    	else
			        i += 3;
	    	}
		}
		else if (i == n-2)
		{
			if (A[i+1] - A[i] > 20)
			{
				cnt += 2;
				break;
			}
			else
			{
				cnt += 1;
				break;
			}
		}
		else
		{
			cnt += 2;
			break;
		}
	}
	cout << cnt << endl;

	return 0;
}

