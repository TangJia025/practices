#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> seq;

bool exist(vector<int> &A, int a);

int main()
{
	while (cin >> n >> m)
    {
		for (int i = 0; i < m; i++)
		{
			int a;
			cin >> a;
			seq.push_back(a);
		}
		vector<int> mem;
		int miss = 0;
		for (int i = 0; i < m; i++)
	    {
			if (exist(mem, seq[i]))
				continue;
			else
			{
				if (mem.size() < n)
					mem.push_back(seq[i]);
				else
				{
					mem.push_back(seq[i]);
					mem.erase(mem.begin());
				}
				miss++;
			}
		}
		cout << "总共缺页 ：" << miss << endl;
		seq.clear();
	}
	return 0;
}

bool exist(vector<int> &A, int a)
{
	for (int i = 0; i < A.size(); i++)
		if (A[i] == a)
			return true;
	return false;
}


