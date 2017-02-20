#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MN 204
using namespace std;

int p[MN];
int n;
bool vis[MN];
bool g[MN][MN];

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

int T=0;

int main()
{
  int m,i,j,k;
  //freopen("3692.in","r",stdin);
  //freopen("3692.out","w",stdout);
  scanf("%d%d%d",&n,&m,&k);
  while(!(n==0&&m==0&&k==0))
  {
    memset(g,1,sizeof(g));
    memset(p,0,sizeof(p));
    for (i=1;i<=k;i++)
    {
      int u,v;
      scanf("%d%d",&u,&v);
      g[u][v]=false;
    }
    int ans=0;
    for (i=1;i<=m;i++)
    {
      memset(vis,0,sizeof(vis));
      if (find(i)) ans++;
    }
    printf("Case %d: %d\n",++T,n+m-ans);
    scanf("%d%d%d",&n,&m,&k);
  }
  return 0;
}
