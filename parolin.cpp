#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string A;
	while (cin >> A)
	{
		int n = A.size();
		int mat[n][n];
		fill(mat[0], mat[0] + n * n, 0);
		for (int i = 0; i < n; i++) mat[i][i] = 1;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < n - i; j++)
			{
				int row = j;
				int col = j + i;
				if (A[row] == A[col])
					mat[row][col] = mat[row+1][col-1] + 2;
				else
					mat[row][col] = max(mat[row][col-1], mat[row+1][col]);
			}
		}
		cout << mat[0][n-1];
	}
	return 0;
}

