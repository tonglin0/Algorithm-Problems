#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct mat{
	int h,w;
	int s[25][25];
	mat(){memset(s,0,sizeof(s));}
	mat(int h,int w):h(h),w(w){memset(s,0,sizeof(s));}
};

mat cheng(mat a,mat b)
{
  mat c(a.h,b.w);
  int i,j,k;
  for (i=1;i<=a.h;i++)
    for (j=1;j<=b.w;j++)
      for (k=1;k<=a.w;k++)
        c.s[i][j]=(c.s[i][j]+a.s[i][k]*b.s[k][j])%1000;
  return c;
}

mat mat_pow(mat a,int b)
{
  mat t;t=a;
  mat ans(a.h,a.w);
  for (int i=1;i<=a.h;i++)
    ans.s[i][i]=1;
  while(b)
  {
    if (b&1)
      ans=cheng(ans,t);
    b>>=1;
    t=cheng(t,t);
  }
  return ans;
}

int main()
{
  freopen("2157.in","r",stdin);
  freopen("2157.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d%d",&n,&m)==2)
  {
    if (n==0&&m==0)
      break;
	mat a(n,n);
    for (i=1;i<=m;i++)
    {
      int u,v;
      scanf("%d%d",&u,&v);
      u++;v++;
      a.s[u][v]=1;
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
	  int u,v,d;
	  scanf("%d%d%d",&u,&v,&d);
	  u++;v++;
	  mat t(n,n);
	  t=mat_pow(a,d);
	  printf("%d\n",t.s[u][v]);
	}
  }
  return 0;
}
