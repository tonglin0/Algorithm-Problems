#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define f(i,j) a.s[i+1][j+1]
#define lint long long
using namespace std;

struct mat{
	int h,w;
	lint s[55][55];
	mat(){memset(s,0,sizeof(s));}
	mat(int h,int w):h(h),w(w){memset(s,0,sizeof(s));}
};

lint MOD;

mat cheng(mat a,mat b)
{
  mat c(a.h,b.w);
  for (int i=1;i<=a.h;i++)
    for (int j=1;j<=b.w;j++)
      for (int k=1;k<=a.w;k++)
        c.s[i][j]=(c.s[i][j]+a.s[i][k]*b.s[k][j])%MOD;
  return c;
}

mat mat_pow(mat a,lint b)
{
  mat t;t=a;
  mat ans(a.h,a.w);
  for (int i=1;i<=a.h;i++)
    ans.s[i][i]=1;
  while(b)
  {
    if (b&1)
      ans=cheng(ans,t);
    t=cheng(t,t);
    b>>=1;
  }
  return ans;
}

int main()
{
  freopen("3483.in","r",stdin);
  freopen("3483.out","w",stdout);
  lint n,i,j,k,x,m;
  while(scanf("%I64d%I64d%I64d",&n,&x,&MOD)==3)
  {
    if (n+x+MOD<0)
      break;
    mat a(x+2,x+2);
    a.s[1][1]=x%MOD;
    for (i=2;i<=x+1;i++)
    {
      a.s[i][1]=a.s[i][i]=x%MOD;
      for (j=2;j<=i-1;j++)
        a.s[i][j]=(a.s[i-1][j-1]+a.s[i-1][j])%MOD;
	}/*
	f(0,0)=x%MOD;
	for (i=1;i<=x;i++)
	{
	  f(i,0)=f(i,i)=x%MOD;
	  for (j=1;j<i;j++)
	    f(i,j)=(f(i-1,j-1)+f(i-1,j))%MOD;
	}*/
	a.s[x+2][x+1]=a.s[x+2][x+2]=1;
	a=mat_pow(a,n);
	mat ans(x+2,1);
	for (i=1;i<=x+1;i++)
	  ans.s[i][1]=x%MOD;
	ans=cheng(a,ans);
	printf("%I64d\n",ans.s[x+2][1]);
  }
  return 0;
}
