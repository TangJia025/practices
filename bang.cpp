#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> seq;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
            if (a == 1)
			{
				seq.push_back(b);
				sort(seq.begin(), seq.end());
			}
			else
			{
				vector<int>::iterator iter = seq.begin();
				for (; iter != seq.end(); iter++)
				{
					if (*iter == b)
					{
						seq.erase(iter);
						break;
					}
				}
			}
			if (seq.size() < 3)
				cout << "No" << endl;
			else
			{
				if (seq[seq.size() - 1] < accumulate(seq.begin(), seq.end() - 1, 0))
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			}
		}
	}
	return 0;
}




