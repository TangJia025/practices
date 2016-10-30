#include <map>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
	int x, y;
	Node(int x1, int y1) : x(x1), y(y1){}
	friend bool operator <(Node p, Node q)
	{
		return p.y < q.y;
	}
};

vector<int> topKFrequent(vector<int> &nums, int k)
{
	int len = nums.size();
	map<int, int> cnt;
	for (int i = 0; i < len; i++)
		cnt[nums[i]]++;

	priority_queue<Node> q;
	map<int, int>::iterator iter = cnt.begin();
    for (int i = 0; iter != cnt.end(); i++, iter++)
	{
		if (i < k)
		{
			q.push(Node(iter->first, iter->second));
		}
		else
		{
			if (q.top() < Node(iter->first, iter->second))
			{
				q.pop();
				q.push(Node(iter->first, iter->second));
			}
		}
	}
	vector<int> res;
	while (!q.empty())
	{
		res.push_back(q.top().x);
		q.pop();
	}
	return res;
}

int main()
{
	int k;
	while (cin >> k)
	{
		vector<int> A;
		for (int i = 0; i < 7; i++)
		{
			int a;
			cin >> a;
			A.push_back(a);
		}
		vector<int> res = topKFrequent(A, k);
		for (int i = 0; i < k; i++)
			cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}


