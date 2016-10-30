#include <stdio.h>
#include <string.h>
#define N 1000000
int main()
{
	int T;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			char str[N];
			scanf("%s", str);
			int ht[255];
			for (int i = 0; i < strlen(str); i++)
				ht[str[i]]++;
			int i = 0; 
			for (; i < strlen(str); i++)
				if (ht[str[i]] == 1)
					break;
			printf("%c\n", str[i]);
		}
	}
	return 0;
}
			
