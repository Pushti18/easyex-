#include<bits/stdc++.h>
using namespace std;
const int D=2003,N=D+1;
long long t,T,n,k,l,m,s,S[N][N],f[N],q[N],e[N];
int Q(long long a,int b)
{
	t=1;
	while(b>0)
	{
		if(b&1)
			(t*=a)%=D;
		(a*=a)%=D,b/=2;
	}
	return t;
}
void F(long long *a,long long *b,long long *c)
{
	memset(e,0,sizeof(e));
	for(int i=0;i<=D;i++)
		for(int j=0;j<=i;j++)
			(c[i]+=a[j]*b[i-j])%=D;
}
int main()
{
	for(int i=1;i<=D;i++)
		S[i][1]=1;
	for(int i=1;i<=D;i++)
		for(int j=2;j<=D;j++)
			S[i][j]=(S[i-1][j-1]+S[i-1][j]*j)%D;
	cin>>T;
	while(T--&&cin>>n>>k>>l>>m)
	{
		s=1;
		for(int i=D;i>=0;i--)
			f[i]=s*Q(k,n+i-D)%D,(s*=n+i)%=D;
		for(int i=1;i<=D;i++)
			q[i]=S[m][i];
		while(l>0)
		{
			if(l&1)
				F(f,q,e),memcpy(f,e,sizeof(e));
			F(q,q,e),memcpy(q,e,sizeof(e)),l/=2;
		}
		cout<<f[D]*Q(Q(k,n),D-2)%D<<'\n';
	}
	return 0;
}