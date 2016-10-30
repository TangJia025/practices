#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define N 200
int main()
{
	int n, m, P;
	cin >> n >> m >> P;
	vector<vector<int> > A;
	for (int i = 0; i < n; i++)
	{
		vector<int> vec;
		for (int j = 0; j < m; j++)
		{
			int a;
			cin >> a;
			vec.push_back(a);
		}
		A.push_back(vec);
	}
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	vector<vector<int> > B(n, vector<int>(m, N));
	vector<vector<bool> > C(n, vector<bool>(m, false));
	vector<vector<int> > D(n, vector<int>(m, 0));
	B[0][0] = 0;
	C[0][0] = true;
	while (!q.empty())
	{
		pair<int, int> pa = q.front();
		q.pop();
		int x = pa.first;
		int y = pa.second;
		if (x-1 >= 0 && A[x-1][y] == 1 && C[x-1][y] == false && B[x-1][y] > (B[x][y] + 3))
		{
			C[x-1][y] = true;
			B[x-1][y] = B[x][y] + 3;
			D[x-1][y] = 2;
			q.push(make_pair(x-1, y));
		}
		if (x+1 < n && A[x+1][y] == 1 && C[x+1][y] == false)
		{
			C[x+1][y] = true;
			B[x+1][y] = B[x][y];
			D[x+1][y] = 1;
			q.push(make_pair(x+1, y));
		}
		if (y+1 < m && A[x][y+1] == 1 && C[x][y+1] == false && B[x][y+1] > B[x][y] + 1)
		{
			C[x][y+1] = true;
			B[x][y+1] = B[x][y] + 1;
			D[x][y+1] = 4;
			q.push(make_pair(x, y+1));
		}
	}
    if (B[0][m-1] > P)
		cout << "Can not escape!" << endl;
	vector<pair<int, int> > res;
	int i = 0, j = m-1;
	res.push_back(make_pair(i, j));
    do
	{
		if (D[i][j] == 1)
		{
			i = i-1;
		}
		else if(D[i][j] == 2)
		{
			i = i+1;
		}
		else if (D[i][j] == 4)
		{
			j = j-1;
		}
		res.push_back(make_pair(i, j));
	}while (i != 0 && j != 0);

	for (int k = res.size()-1; k > 0; k--)
		cout << "[" << res[k].first << "," << res[k].second << "],";
	cout << "[" << res[0].first << "," << res[0].second  << "]" << endl;

	return 0;
}




