#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
    while (cin >> N)
	{
		vector<vector<int> > A(N, vector<int>(N, 0));
		vector<vector<int> > set(N, vector<int>(N, 0));
		int i, j, cnt;
		i = j = 0;
		cnt = 1;
		int direction = 1;   //  1表示向右，2表示向下，3表示向左，4表示向上；
		while (cnt <= N*N)
		{
			A[i][j] = cnt;
			set[i][j] = 1;
			cnt++;
			if (direction == 1)
			{
				if (j < N-1 && set[i][j+1] == 0)
					j++;
				else
				{
					direction = 2;
					i++;
				}
			}
			else if (direction == 2)
			{
				if (i < N-1 && set[i+1][j] == 0)
					i++;
				else
				{
					direction = 3;
					j--;
				}
			}
			else if (direction == 3)
			{
				if (j >= 1 && set[i][j-1] == 0)
					j--;
				else
				{
					direction = 4;
					i--;
				}
			}
			else
			{
				if (i >= 1 && set[i-1][j] == 0)
					i--;
				else
				{
					direction = 1;
					j++;
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

		

