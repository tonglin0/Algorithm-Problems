#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define C(i,j) cc[i][j]
#define lint long long
using namespace std;

lint MOD;
lint an[109],bn[109];
lint cc[55][55];

struct mat{
	int h,w;
	lint s[55][55];
	mat(){memset(s,0,sizeof(s));}
	mat(int h,int w):h(h),w(w){memset(s,0,sizeof(s));}
};

lint pow_mod(lint a,lint b,lint c)
{
  lint ans=1,t=a%c;
  while(b)
  {
    if (b&1)
      ans=ans*t%c;
    b>>=1;
    t=t*t%c;
  }
  return ans;
}

mat cheng(mat a,mat b)
{
  mat c(a.h,b.w);
  lint i,j,k;
  for (i=0;i<a.h;i++)
    for (j=0;j<b.w;j++)
      for (k=0;k<a.w;k++)
        c.s[i][j]=(c.s[i][j]+a.s[i][k]*b.s[k][j])%MOD;
  return c;
}

mat mat_pow(mat a,lint b)
{
  mat t;t=a;
  mat ans(a.h,a.w);
  for (lint i=0;i<a.h;i++)
    ans.s[i][i]=1;
  while(b)
  {
    if (b&1)
      ans=cheng(t,ans);
    t=cheng(t,t);
    b>>=1;
  }
  return ans;
}

int main()
{
  freopen("3509.in","r",stdin);
  freopen("3509.out","w",stdout);
  lint n,ca,i,j,k,m,a,b,f1,f2,s1,s2;
  scanf("%lld",&ca);
  while(ca--)
  {
    scanf("%lld%lld%lld%lld%lld%lld%lld",&f1,&f2,&a,&b,&k,&n,&MOD);
    s1=pow_mod(f1,k,MOD);
    s2=(pow_mod(f2,k,MOD)+s1)%MOD;
    if (n==1)
    {
      printf("%lld\n",s1);
      continue;
	}
	else if (n==2)
	{
	  printf("%lld\n",s2);
	  continue;
	}
	memset(cc,0,sizeof(cc));
	cc[0][0]=1%MOD;
	for (i=1;i<=k+2;i++)
	{
	  cc[i][0]=cc[i][i]=1%MOD;
	  for (j=1;j<i;j++)
	    cc[i][j]=(cc[i-1][j-1]+cc[i-1][j])%MOD;
	}
	an[0]=1%MOD;bn[0]=1%MOD;
	for (i=1;i<=k+1;i++)
	{
	  an[i]=an[i-1]*a%MOD;
	  bn[i]=bn[i-1]*b%MOD;
	}
	mat t(k+2,k+2);
	for (j=0;j<=k;j++)
	  for (lint p=0;p<=k-j;p++)
	    t.s[j][p]=(cc[k-j][p]*an[k-j-p]%MOD*(bn[p]%MOD)%MOD);
	for (i=0;i<=k;i++)
	  t.s[k+1][i]=cc[k][i]*an[k-i]%MOD*(bn[i]%MOD)%MOD;
	t.s[k+1][k+1]=1%MOD;
	mat oi(k+2,1);
	for (i=0;i<=k;i++)
	  oi.s[i][0]=pow_mod(f1,i,MOD)*pow_mod(f2,k-i,MOD)%MOD;
	oi.s[k+1][0]=s2;
	t=mat_pow(t,n-2);
	oi=cheng(t,oi);
	printf("%lld\n",oi.s[k+1][0]%MOD);
  }
  return 0;
}
