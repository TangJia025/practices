#include <iostream>

using namespace std;

int main()
{
	int x[1000] = {0};
	int y[1000] = {0};
    int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> x[i];
		for (int i = 0; i < n; i++)
			cin >> y[i];
		int count = x[0] + y[0];
		for (int i = 1; i < n; i++)
			if (count > x[i] + y[i])
		        count = x[i] + y[i];
		cout << count - 2 << endl;
	}
	return 0;
}


