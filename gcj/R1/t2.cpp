#include <stdio.h>
 
int ar[100000000];
int main()
{
	int i;
	for (i=0; i<100000000; i++) ar[i] = i;
	printf("%d\n",ar[50000000]);
}
