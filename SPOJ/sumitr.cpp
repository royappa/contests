#include <iostream>
int m[101][101],r,i,j,D;main(){scanf("%d",&D);while(D-->0){scanf("%d",&r);for(i=1;i<=r;i++)for(j=1;j<=i;j++)scanf("%d",&m[i][j]);
i=r-1;do for(j=1;j<=i;j++)m[i][j]+=m[i+1][j]>?m[i+1][j+1];while (i--);printf("%d\n",m[1][1]);}}