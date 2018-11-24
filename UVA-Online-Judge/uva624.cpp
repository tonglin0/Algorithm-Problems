#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int v[1009];
int f[23][10009];
bool g[23][10009];
bool vis[23];

int main()
{
  freopen("624.in","r",stdin);
  freopen("624.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d%d",&m,&n)==2)
  {
    for (i=1;i<=n;i++)
      scanf("%d",&v[i]);
    memset(g,0,sizeof(g));
    memset(f,0,sizeof(f));
    for (i=1;i<=n;i++)
      for (j=0;j<=m;j++)
        if (j<v[i])
        {
          f[i][j]=f[i-1][j];
          g[i][j]=false;
		}
		else
		{
		  if (f[i-1][j]>f[i-1][j-v[i]]+v[i])
		  {
		    f[i][j]=f[i-1][j];
		    g[i][j]=false;
		  }
		  else
		  {
		    f[i][j]=f[i-1][j-v[i]]+v[i];
		    g[i][j]=true;
		  }
		}
	memset(vis,0,sizeof(vis));
	i=n;j=m;
	int ans=0;
	while(i>0&&j>0)
	{
	  if (g[i][j])
	  {
	    vis[i]=true;
	    ans+=v[i];
	    j-=v[i];
	    i--;
	  }
	  else
	    i--;
	}
	for(i=1;i<=n;i++)
	  if (vis[i])
	    printf("%d ",v[i]);
	printf("sum:%d\n",ans);
  }
  return 0;
}
