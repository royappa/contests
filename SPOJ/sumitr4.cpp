#include <iostream>
#define z std::cin>>
int m[5000],e[5000],r,i,D;int f(int x,int y){ i=(x-1)*x/2+y;return e[i]=e[i]?e[i]:x-r?m[i]+(f(x+1,y)>?f(x+1,y+1)):m[i];}main(){z D;while(D-->0){z r;for(i=1;i<=r*(r+1)/2;i++)z m[i],e[i]=0;std::cout<<f(1,1)<<"\n";}}