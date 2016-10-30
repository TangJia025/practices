#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int> &, int start);
void merge(vector<int> &, int start, int end);

int main()
{
	string s;
	while (cin >> s)
	{
		int len = s.size();
		vector<int> pre(len, -1);
		for (int i = 0; i < len; i++) pre[i] = i;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int start, end;
			cin >> start >> end;
			merge(pre, start, end);
		}
		for (int i = 0; i < len-1; i++)
		{
			int ri = find(pre, i);
			for (int j = i+1; j < len; j++)
			{
				int rj = find(pre, j);
				if (ri == rj && s[i] > s[j])
					swap(s[i], s[j]);
			}
		}
		cout << s << endl;
	}
	return 0;
}

int find(vector<int> &pre, int start)
{
	int r = start;
	while (r != pre[r])
		r = pre[r];
	pre[start] = r;
	return r;
}

void merge(vector<int> &pre, int start, int end)
{
	int sr = find(pre, start);
	int er = find(pre, end);
	if (sr < er)
		pre[er] = sr;
	else
		pre[sr] = er;
}
	


