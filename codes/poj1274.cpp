#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int p[203];
bool g[203][203],vis[203];
int n;

bool find(int u)
{
  for (int i=1;i<=n;i++)
    if (!vis[i]&&g[i][u])
    {
      vis[i]=true;
      if (!p[i]||find(p[i]))
      {
        p[i]=u;
        return true;
      }
    }
  return false;
}

int main()
{
  //freopen("1274.in","r",stdin);
  //freopen("1274.out","w",stdout);
  int i,j,m,k;
  while(scanf("%d%d",&n,&m)==2)
  {
    memset(p,0,sizeof(p));
    memset(g,0,sizeof(g));
    for(i=1;i<=n;i++)
    {
      scanf("%d",&k);
      for (j=1;j<=k;j++)
      {
        int u;
        scanf("%d",&u);
        g[i][u]=true;
      }
    }
    int ans=0;
    for (i=1;i<=m;i++)
    {
      memset(vis,0,sizeof(vis));
      if (find(i)) ans++;
    }
    printf("%d\n",ans);
  }
  return 0;
}
