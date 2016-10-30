#include <iostream>

using namespace std;

struct Seg
{
	int x1, y1, x2, y2;
};

bool Joint(Seg s1, Seg s2);
bool dfs(vector<int> &res, map<int, vector<int> > &joint, seg);

int main()
{
	int n;
	while (cin >> n)
	{
		Seg seg[n];
		for (int i = 0; i < n; i++)
			cin >> seg[i].x1 >> seg[i].y1 >> seg[i].x2 >> seg[i].y2;
		map<int, vector<int> > joint;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n && j != i; j++)
			{
				if (Joint(seg[i], seg[j]))
					map[i].push_back(j);
			}
		}
		vector<int> res;
		for (int i = 0; i < n; i++)
		{
			res.push_back(i);
			if (dfs(res, joint, seg))
				break;
			res.erase(res.begin());
		}


	}
	return 0;
}

bool Joint(Seg s1, Seg s2)
{
	if ((s1.x1 == s1.x2 && s2.x1 == s2.x2) || (s1.y1 == s1.y2 && s2.y1 == s2.y2))
		return false
	if (s1.x1 == s1.x2)
	{
		return (s1.x1 > s2.x1 && s1.x1 <= s2.x2) && (s2.y1 >= s1.y1 && s2.y1 <= x1.y2);
	}
	else
		return (s2.x1 >= s1.x1 && s2.x1 <= s1.x2) && (s1.y1 >= s2.y1 && s1.y1 <= s2.y2);
}

bool dfs(vector<int> &res, map<int, vector<int> &joint, seg)
{
	if (res.size() == 4)
       return Joint(seg[res[0]], seg[res[3]]);
	map<int, vector<int> >::iterator iter = joint.begin();
