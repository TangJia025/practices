#include <iostream>

using namespace std;

const int N = 1e9 + 7;
typedef long long ll;

int main()
{
	ll x;
	while (cin >> x)
	{
		int time = 4;
		int i = 1;
		for (; i <= 150000; i++)
		{
			int remainder = (time * (x+1) - 1) % N;
			if (remainder == 0)
				break;
			time *= 2;
		}
		if (i > 150000)
			cout << "-1" << endl;
		else
		{
			int res = i / 3 + 1;
			cout << res << endl;
		}
	}
	return 0;
}
