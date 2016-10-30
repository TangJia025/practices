#include <math.h>
#include <stdio.h>

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		double a = (double)n;
		double res = 0;
		while (m--)
		{
			res += a;
			a = sqrt(a);
		}
		printf("%.2lf\n", res);
	}
	return 0;
}

