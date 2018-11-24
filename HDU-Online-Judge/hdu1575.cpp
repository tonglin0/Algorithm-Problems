#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MOD 9973
using namespace std;

struct mat{
	int h,w;
	int s[21][21];
	mat(){memset(s,0,sizeof(s));}
	mat(int h,int w):h(h),w(w){memset(s,0,sizeof(s));}
};

mat cheng(mat a,mat b)
{
  mat c(a.h,b.w);
  for (int i=1;i<=a.h;i++)
    for (int j=1;j<=c.w;j++)
      for (int k=1;k<=a.w;k++)
        c.s[i][j]=(c.s[i][j]+a.s[i][k]*b.s[k][j])%MOD;
  return c;
}

int main()
{
  freopen("1575.in","r",stdin);
  freopen("1575.out","w",stdout);
  int ca,n,i,j,k,m;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d%d",&n,&k);
    mat a(n,n);
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        scanf("%d",&a.s[i][j]);
    mat t;t=a;
    mat ans(n,n);
    for (i=1;i<=n;i++)
      ans.s[i][i]=1;
    while(k)
    {
      if (k&1)
        ans=cheng(ans,t);
      k>>=1;
      t=cheng(t,t);
	}
	int s=0;
	for (i=1;i<=n;i++)
	  s=(s+ans.s[i][i])%MOD;
	printf("%d\n",s);
  }
  return 0;
}
