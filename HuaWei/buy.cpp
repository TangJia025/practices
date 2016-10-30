#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Product
{
	int v, w, q;
};

bool comp(Product p1, Product p2)
{
	return p1.q < p2.q;
}

int dp(vector<int> buy, int N, int i);

int N;
int m;
vector<Product> P;

int main()
{
	while (cin >> N >> m)
	{
		Product pro = {0, 0, 0};
		P.push_back(pro);
		for (int i = 1; i <= m; i++)
		{
			Product p;
			cin >> p.v >> p.w >> p.q;
			P.push_back(p);
		}
		sort(P.begin(), P.end(), comp);
		vector<int> buy;
		cout << dp(buy, N, 0) << endl;
		P.clear();
	}
	return 0;
}

int dp(vector<int> buy, int N, int i)
{
	int result = 0;
	if (i == m)
		result = 0; 
	else
	{
		if (P[i].q == 0 || (find (buy.begin(), buy.end(), P[i].q) != buy.end()))
		{
			if (N >= P[i].v)
			{
		    	vector<int> buy1(buy);
		    	buy1.push_back(i);
				result = max(dp(buy1, N - P[i].v, i+1) + P[i].v * P[i].w, dp(buy, N, i+1));
			}
			else
				result = dp(buy, N, i+1);
		}
		else
			result = dp(buy, N, i+1);
	}
	return result;
}
	
			


		
