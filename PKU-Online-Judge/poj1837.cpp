#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define f(i,j) dp[i][(j+7501)]
using namespace std;

int p[31];
int dp[22][15004];
int v[25][34];

int main()
{
  freopen("1837.in","r",stdin);
  freopen("1837.out","w",stdout);
  int n,i,j,k,m,c;
  scanf("%d%d",&c,&n);
  for (i=1;i<=c;i++)
    scanf("%d",&p[i]);
  for (i=1;i<=n;i++)
  {
    int v0;
    scanf("%d",&v0);
    for (j=1;j<=c;j++)
      v[i][j]=v0*p[j];
  }
  memset(dp,0,sizeof(dp));
  f(0,0)=1;
  for (i=1;i<=n;i++)
    for (j=7500;j>=-7500;j--)
      for (k=1;k<=c;k++)
        if (j-v[i][k]>=-7500&&j-v[i][k]<=7500)
          f(i,j)+=f(i-1,j-v[i][k]);
  printf("%d\n",f(n,0));
  return 0;
}
