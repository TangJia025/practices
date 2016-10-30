#include <iostream>

using namespace std;

int main()
{
	int A, B;
	while (cin >> A >> B)
	{
		int cnt = 0;
		int m, n;
		if (A % 19 == 0)
			m = A / 19;
		else
			m = A / 19 + 1;
		n = A / 9;
		for (int i = m; i <= n; i++)
		{
			if ((A + i) % 5 == 0)
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}

