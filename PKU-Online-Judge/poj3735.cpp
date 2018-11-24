#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define lint long long
using namespace std;

struct mat{
	int h,w;
	lint s[105][105];
	mat(){memset(s,0,sizeof(s));}
	mat(int h,int w):h(h),w(w){memset(s,0,sizeof(s));}
};
/*
mat cheng(mat a,mat b)
{
  int i,j,k;
  mat c(a.h,b.w);
  for (i=1;i<=a.h;i++)
    for (j=1;j<=b.w;j++)
        for (k=1;k<=a.w;k++)
          c.s[i][j]+=a.s[i][k]*b.s[k][j];
  return c;
}
*/
mat cheng(mat a,mat b)
{
  int i,j,k;
  mat c(a.h,b.w);
  for (k=1;k<=a.w;k++)
    for (i=1;i<=a.h;i++)
      if (a.s[i][k])
        for (j=1;j<=b.w;j++)
          c.s[i][j]+=a.s[i][k]*b.s[k][j];
  return c;
}

mat mat_pow(mat a,int b)
{
  mat t;t=a;
  mat ans(a.h,a.w);
  for (int i=1;i<=ans.h;i++)
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
  freopen("3735.in","r",stdin);
  freopen("3735.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d%d%d",&n,&m,&k)==3)
  {
    if (n+m+k==0)
      break;
    mat t(n+1,n+1);
    for (i=1;i<=n+1;i++)
      t.s[i][i]=1;
    mat oi(n+1,1);
    oi.s[n+1][1]=1;
    char st[3];
    int u,v;
	for (i=1;i<=k;i++)
    {
      scanf("%s",st);
      if (st[0]=='g')
      {
        scanf("%d",&u);
        t.s[u][n+1]++;
	  }
	  else if (st[0]=='e')
	  {
	    scanf("%d",&u);
	    memset(t.s[u],0,sizeof(t.s[u]));
	  }
	  else
	  {
	    scanf("%d%d",&u,&v);
	    for (j=1;j<=n+1;j++)
	      swap(t.s[u][j],t.s[v][j]);
	  }
	}
	oi=cheng(mat_pow(t,m),oi);
	printf("%I64d",oi.s[1][1]);
	for (i=2;i<=n;i++)
	  printf(" %I64d",oi.s[i][1]);
	printf("\n"); 
  }
  return 0;
}

