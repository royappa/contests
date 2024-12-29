#include <stdio.h>
#include <string>
int m[10001], e[10001],n,r,i,j,D;
int f(int x,int y)
{int t=(x-1)*x/2+y;return e[t]!=-1?e[t] : (x-r?m[t]+(f(x+1,y)>?f(x+1,y+1)):m[t]);}

main()
{
scanf("%d",&D);
while(D-->0)
{scanf("%d",&r);
for(i=1; i <= r*(r+1)/2;i++)
	scanf("%d",&m[i]),e[i]=-1;
printf("%d\n",f(1,1));}
}
