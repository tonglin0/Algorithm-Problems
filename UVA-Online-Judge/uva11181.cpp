#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;

double p[24];
double f[24];
bool vis[24];
double ff;

void dfs(int n,int r,int k)
{
  if (k==n+1&&r==0)
  {
    double ans=1;
    for (int i=1;i<=n;i++)
      if (vis[i])
        ans*=p[i];
      else
        ans*=(1-p[i]);
    for (int i=1;i<=n;i++)
      if (vis[i])
        f[i]+=ans;
    ff+=ans;
    return ;
  }
  if (k==n+1)
    return ;
  if (r>0)
  {
    vis[k]=true;
    dfs(n,r-1,k+1);
    vis[k]=false;
    dfs(n,r,k+1);
    return ;
  }
  else
  {
    vis[k]=false;
    dfs(n,r,k+1);
    return ;
  }
}

int main()
{
  freopen("11181.in","r",stdin);
  freopen("11181.out","w",stdout);
  int n,i,j,k,m,ii=0;
  while(scanf("%d%d",&n,&m)==2&&(n+m))
  {
    printf("Case %d:\n",++ii);
    for (i=1;i<=n;i++)
      scanf("%lf",&p[i]);
    ff=0;
	memset(f,0,sizeof(f));
	dfs(n,m,1);
    for (i=1;i<=n;i++)
      printf("%.6lf\n",f[i]/ff);
  }
  return 0;
}
