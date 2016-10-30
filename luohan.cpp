#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		map<int, int> data;
		for (int i = 0; i < n; i++)
		{
			int idx, w, h;
			cin >> idx >> w >> h;
			data[w] = h;
		}
		map<int, int>::iterator iter = data.begin();
		vector<int> height;
		for (; iter != data.end(); iter++)
			height.push_back(iter->second);

		int acd[n], res;
		acd[0] = res = 1;
		for (int i = 1; i < n; i++)
		{
			acd[i] = 1;
			for (int j = i-1; j >= 0; j--)
			{
				if (height[i] >= height[j])
					acd[i] = max(acd[i], acd[j]+1);
			}
			res = max(res, acd[i]);
		}
		cout << res << endl;
	}
	return 0;
}

