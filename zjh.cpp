#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<char, int> keep;

bool Trans(string s, vector<int> &A);
int Level(vector<int> &A);

int main()
{
	keep['J'] = 11;
	keep['Q'] = 12;
	keep['K'] = 13;
	keep['A'] = 14;
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		vector<int> A;
		vector<int> B;
		if (!Trans(s1, A) || !Trans(s2, B))
		{
			cout << "-2" << endl;
			continue;
		}
		int la = Level(A);
		int lb = Level(B);
		if (la > lb)
		{
			cout << "1" << endl;
		}
		else if (la < lb)
		{
			cout << "-1" << endl;
		}
		else
		{
			if (la == 4 || la == 3)
			{
				if (A[0] > B[0])
					cout << "1" << endl;
				else if (A[0] < B[0])
					cout << "-1" << endl;
				else
					cout << "0" << endl;
			}
			else if (la == 2)
			{
				if (A[2] > B[2])
					cout << "1" << endl;
				else if (A[2] < B[2])
					cout << "-1" << endl;
				else
				{
					if (A[0] > B[0])
						cout << "1" << endl;
					else if (A[0] < B[0])
						cout << "-1" << endl;
					else 
						cout << "0" << endl;
				}
			}
			else
			{
				if (A[2] > B[2])
					cout << "1" << endl;
				else if (A[2] < B[2])
					cout << "-1" << endl;
				else 
				{
					if (A[1] > B[1])
						cout << "1" << endl;
					else if (A[1] < B[1])
						cout << "-1" << endl;
					else 
					{
						if (A[0] > B[0])
							cout << "1" << endl;
						else if (A[0] < B[0])
							cout << "-1" << endl;
						else 
							cout << "0" << endl;
					}
				}
			}
		}

	}
	return 0;
}

bool Trans(string s, vector<int> &A)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (keep.find(s[i]) != keep.end())
		{
			A.push_back(keep[s[i]]);
		}
		else if (s[i] == '1')
		{
			if (s[i+1] != '0')
				return false;
			else
			{
				A.push_back(10);
				i++;
			}
		}
		else if (s[i] >= '2' || s[i] <= 9)
		{
			A.push_back(s[i] - '0');
		}
		else
		{
			return false;
		}
	}
	sort(A.begin(), A.end());
	return true;
}

int Level(vector<int> &A)
{
	if (A[0] == A[2])    //  豹子
		return 4;
	else if ((A[0]+1 == A[1]) && (A[1]+1 == A[2]))   //  顺子
		return 3;
	else if ((A[0] == A[1]) || (A[1] == A[2]))   //  对子
		return 2;
	else    //  普通
		return 1;
}



