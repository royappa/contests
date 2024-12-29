#include <stdio.h>

main()
{
	printf("1\n100000 100000 500000\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 1; j <= 100000; j++)
		{
			printf("%d\n", j);
		}
	}
}
