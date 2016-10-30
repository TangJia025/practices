#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int A[n];
	for (int i = 0; i < n; i++) cin >> A[i];
    int t = m;
	int l = 0;
	while (t)
	{
		l++;
		t >> 1;
	}
	vector<int> B;
	vector<int> C;
	for (int i = 0; i < n; i++)
	{
		if ((A[i] & (1 << l)) == 0)
			B.push_back(A[i]);
		else
			C.push_back(A[i]);
	}
	int res;
	res += B.size() * C.size();
	for (int i = 0; i < B.size()-1; i++)
	{
		for (int j = i+1; j < B.size(); j++)
        {
			if ((B[i] ^ B[j]) > m)
				res++;
		}
	}
	for (int i = 0; i < C.size()-1; i++)
	{
		for (int j = i+1; j < C.size(); j++)
        {
			if ((C[i] ^ C[j]) > m)
				res++;
		}
	}
	cout << res << endl;

	return 0;
}





