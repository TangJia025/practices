#include <iostream>
#include <string>

using namespace std;

void compute(string &A0, string &B0);
int A, B, C, D, E, Err, Pri;

int main()
{
	string s;
	while (cin >> s)
	{
		A = B = C = D = E = Err = Pri = 0;
		int i = 0;
		while (i < s.size())
		{
			int j;
			if ((j = s.find_first_of(' ', i)) == string::npos)
				j = s.size();
			string s1 = s.substr(i, j-i);
			int k  = s1.find_first_of('~', 0);
			string A = s1.substr(0, k);
			string B = s1.substr(k+1);
			compute(A, B);
			i = j+1;
		}
		cout << A << " " << B << " " << C << " " << D << " " << E << " " << Err << " " << Pri << endl;
	}
	return 0;
}

void compute(string &A0, string &B0)
{
	if (B0.find_last_of("0", string::npos) < B0.find_first_of("255", string::npos)) 
	{
		Err++;
		return;
	}
	int mask = 0;
	int i = 0;
	while (i < B0.size())
	{
		int j;
		j = B0.find_first_of("255", i);
		mask++;
		i = j + 4;
	}
	i = 0;
    int a1, a2, a3, a4;
	a1 = a2 = a3 = a4 = 0;

	int j = A0.find_first_of('.', i);
	string A1 = A0.substr(i, j-i);
	if (A1.empty())
	{
		Err++;
		return;
	}
	for (int k = 0; k < A1.size(); k++)
		a1 = 10 * a1 + (A1[k] - '0');
	if (!(a1 >=1 && a1 <= 255))
	{
		Err++;
		return;
	}
	
	i = j+1;
	j = A0.find_first_of('.', i);
	string A2 = A0.substr(i, j-i);
	if (A2.empty())
	{
		Err++;
		return;
	}
	for (int k = 0; k < A2.size(); k++)
		a2 = 10 * a2 + (A2[k] - '0');
	if (!(a2 >= 0 && a2 <= 255))
	{
		Err++;
		return;
	}

	i = j+1;
	j = A0.find_first_of('.', i);
	string A3 = A0.substr(i, j-i);
	if (A2.empty())
	{
		Err++;
		return;
	}
	for (int k = 0; k < A2.size(); k++)
		a3 = 10 * a3 + (A3[k] - '0');
	if (!(a3 >= 0 && a3 <= 255))
	{
		Err++;
		return;
	}

	i = j+1;
	string A4 = A0.substr(i);
	if (A4.empty())
	{
		Err++;
		return;
	}
	for (int k = 0; k < A4.size(); k++)
		a4 = 10 * a4 + (A4[k] - '0');
	if (!(a4 >= 0 && a4 <= 255))
	{
		Err++;
		return;
	}

	if (a1 >= 1 && a1 <= 126 && mask == 1)
	{
		A++;
		if (a1 == 10)
			Pri++;
	}
	else if (a1 >= 128 && a1 <= 191 && mask == 2)
	{
		B++;
		if (a1 == 172 && a2 >= 16 && a2 <= 31)
			Pri++;
	}
	else if (a1 >= 192 && a1 <= 223 && mask == 3)
	{
		C++;
		if (a1 == 192 && a2 == 168)
			Pri++;
	}
	else if (a1 >= 224 && a1 <= 239 && mask == 4)
		D++;
	else if (a1 >=240 && a1 <= 255 && mask == 4)
		E++;
	else
		Err++;
}
	  










