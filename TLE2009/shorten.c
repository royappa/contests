#define Y 32000
#define X 1000000
#define W [0]
#define q int

int B[X+1],V;

#define a  [1]
#define b  [i]
q main(){q P[Y],F[Y],j,Z=0,i;
	memset(P,0,Y);
	for(i=2;i<2000;i++)
		if(!P b )
			for(j=i*i;j<Y;j+=i)
				P[j]=1;
	for(i=2;i<Y/2;i++)if(!P b )F[Z++]=i;
	q Q[Y][2],PH[Y],M=0,A[Y][2],C=0,R[Y][2],K=0,k,ans;
	while(1){scanf("%d%d",Q[C],Q[C]+1);
		if(Q[C] W==0&&Q[C] a  ==0)break;
		A[C] W=Q[C] W,A[C] a  =Q[C++] a  ;}
		R W W=A W W,R W a  =A W a  ;
		for(i=1;i<C;++i){
			if(A b  W>R[K] a  ){
				        if(R[K] W+X<A b  W){R[++K] W=A b  W,R[K] a  =A b  a  ;continue;}
					        R[K] a  =A[K] a  ;
						        if(A[K] a  <R[K] W+X)continue;
							        R[K+1] W=R[K] a  +1,R[K+1] a  =A[K] a  ;
								        K++;
			}
			if(A b  a  <=R[K] a  )continue;
			if(A b  a  -R[K] W<=X)R[K] a  =A b  a  ;
			else R[K] a  =R[K] W+X,R[K+1] W=R[K] a  +1,R[++K] a  =A b  a  ;}
			if(C>700)return 0;
			for(V=0;V<K+1;++V){q I,last,r[X+1];I=R[V] W;last=R[V] a  ;
				if(I<561)I=561;memset(B,-1,4*(X+1));memset(r,0,4*(X+1));
				q S,fl=0,G[X+1]={0};
				for(i=1;i<Z;i++){q tt=(I>F b )?(I+F b -I%F b ):F b ;if(tt==I+F b )tt-=F b ;S=tt-I;
					q ll=last-I+1;for(j=S;j<ll;j+=F b ){r[j]+=((j+I-1)%(F b -1));B[j]*=F b ;
						if((j+I)!=F b ) G[j]=1;}}for(i=I;i<=last;i++)
							if(!(r[i-I]) && G[i-I]==1 &&!( B[i-I]+i))PH[M++]=i;}
						for(i=0;i<C;++i){k=0,ans=0;while(k<M&&PH[k]<Q b  W)k++;
							while(k<M&&PH[k]<=Q b  a  )printf("%d\n",PH[k]),k++,ans++;
							if(!ans)puts("none");}return 0;
}

