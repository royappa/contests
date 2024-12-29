#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair

const double eps=1E-9;
const double pi=acos(-1);

using namespace std;

const int nm=50002;
const int mm=500002;
const int inf=1000000000;

struct bg {
    int u,v;
};

int n,m;bg a[mm];
int tree[4*nm];

void update(int i,int x,int l,int r,int cs) {
    if (l==r) {
        if (x<tree[cs]) tree[cs]=x;return;
    }
    int m=(l+r)>>1;
    if (i<=m) update(i,x,l,m,cs<<1);else update(i,x,m+1,r,2*cs+1);
    tree[cs]=min(tree[cs<<1],tree[2*cs+1]);
}

int getmin(int u,int v,int l,int r,int cs) {
    if (l>=u && r<=v) return tree[cs];
    if (l>v || r<u) return inf;
    int m=(l+r)>>1;
    return min(getmin(u,v,l,m,cs<<1),getmin(u,v,m+1,r,2*cs+1));
}

int main()
{
    int t,i,j;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;++i) scanf("%d%d",&a[i].u,&a[i].v);
        memset(tree,0x3f,sizeof(tree));
        update(1,0,1,n,1);
        for(i=1;i<=m;++i) {
            j=getmin(a[i].u,n,1,n,1);
            update(a[i].v,j+1,1,n,1);
        }
        printf("%d\n",getmin(n,n,1,n,1));
    }
}