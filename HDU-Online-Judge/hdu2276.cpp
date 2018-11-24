#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

char st[109];

struct mat{
	int h,w;
	int s[109][109];
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
        c.s[i][j]=(c.s[i][j]^(a.s[i][k]&b.s[k][j]));
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
    t=cheng(t,t);
    b>>=1;
  }
  return ans;
}

int main()
{
  freopen("2276.in","r",stdin);
  freopen("2276.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&m)==1)
  {
    scanf("%s",st);
    n=strlen(st);
    mat a(n,n);
    mat ans(n,1);
	for (i=0;i<n;i++)
      ans.s[i+1][1]=st[i]-'0';
    for (i=1;i<=n;i++)
    {
      a.s[i][i]=1;
      if (i==1)
        a.s[i][n]=1;
      else
        a.s[i][i-1]=1;
	}
	a=mat_pow(a,m);
	ans=cheng(a,ans);
	for (i=1;i<=n;i++)
	  printf("%d",ans.s[i][1]);
	printf("\n");
  }
  return 0;
}
