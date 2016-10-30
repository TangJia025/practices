#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void add(string &A, string B);
string multi(string C, string D);

int main()
{
	string C, D;
	while (cin >> C >> D)
	{
		cout << multi(C, D) << endl;
	}
	return 0;
}

void add(string &A, string B)
{
	if (A.empty())
	{
		A = B;
		return;
	}
	int la = A.size();
	int lb = B.size();
	int l = max(la, lb);
	if (la < lb)
	{
		int dis = lb - la;
		while (dis--)
		{
			A = "0" + A;
		}
	}
	else if (la > lb)
	{
		int dis = la - lb;
		while (dis--)
		{
			B = "0" + B;
		}
	}
	int n1, n2;
	n2 = 0;
	for (int i = l-1; i >= 0; i--)
	{
		n1 = (A[i] - '0' + B[i] - '0' + n2) % 10;
		n2 = (A[i] - '0' + B[i] - '0' + n2) / 10;
		A[i] = (char)(n1 + '0');
	}
	if (n2 == 1)
		A = "1" + A;
}

string multi(string C, string D)
{
	if (C.empty() || D.empty()) return "";
	while (!C.empty() && C[0] == '0') C = C.substr(1);
	while (!D.empty() && D[i] == '0') D = D.substr(1);
	if (C.empty() || D.empty()) return "0";
}




