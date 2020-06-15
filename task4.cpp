#include<bits/stdc++.h>
#define LL long long
#define uLL unsigned long long
#define db double
     
using namespace std;
const int N=200+10,mod=1e9+7;
int rd()
{
	int x=0,w=1;char ch=0;
	while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*w;
}
int fpow(int a,int b){int an=1;while(b){if(b&1) an=1ll*an*a%mod;a=1ll*a*a%mod,b>>=1;}return an;}
int ginv(int a){return fpow(a,mod-2);}
int fac[N],iac[N],g[N],f[N][N],pw[N*N];
int C(int a,int b){return b<0||a<b?0:1ll*fac[a]*iac[b]%mod*iac[a-b]%mod;}
int sov(int n,int m)
{
	if(m<0||n<m) return 0;
	if(f[n][m]) return f[n][m];
	for(int i=1;i<=m;++i) f[n][m]=(f[n][m]+1ll*sov(n-i,m-i)*C(m-1,i-1)%mod)%mod;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n-m;++j)
			f[n][m]=(f[n][m]+1ll*sov(n-i-j,m-i)*C(m-1,i-1)%mod*C(n-m,j)%mod*g[j]%mod*fpow(pw[j]-1,i)%mod*pw[i*(i-1)/2]%mod)%mod;
	return f[n][m];
}

int main()
{
	fac[0]=1;
	for(int i=1;i<=200;++i) fac[i]=1ll*fac[i-1]*i%mod;
	iac[200]=ginv(fac[200]);
	for(int i=200;i;--i) iac[i-1]=1ll*iac[i]*i%mod;
	pw[0]=1;
	for(int i=1;i<=200*200;++i) pw[i]=2ll*pw[i-1]%mod;
	g[0]=g[1]=1;
	for(int i=2;i<=200;++i)
	{
		g[i]=pw[i*(i-1)/2];
		for(int j=1;j<i;++j) g[i]=(g[i]-1ll*g[j]*C(i-1,j-1)%mod*pw[(i-j)*(i-j-1)/2]%mod+mod)%mod;
	}
	for(int i=0;i<=200;++i) f[i][0]=pw[i*(i-1)/2];
	int T=rd();
	while(T--)
	{
		int n=rd(),m=/*n-*/rd();
		printf("%d\n",sov(n,m));
	}
	return 0;
}
