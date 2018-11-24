#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cstring>
#define MN 203
using namespace std;

int p[MN];
bool vis[MN];
bool g[MN][MN];
int n;

bool find(int u)
{
  for (int i=1;i<n;i++)
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
  //freopen("1325.in","r",stdin);
  //freopen("1325.out","w",stdout);
  int m,i,j,k;
  scanf("%d",&n);
  while(n)
  {
    memset(p,0,sizeof(p));
    memset(g,0,sizeof(g));
    scanf("%d%d",&m,&k);
    for (i=1;i<=k;i++)
    {
      int u,v;
      scanf("%d",&u);
      scanf("%d%d",&u,&v);
      if (u&&v) g[u][v]=true;
    }
    int ans=0;
    for (i=1;i<m;i++)
    {
      memset(vis,0,sizeof(vis));
      if (find(i)) ans++;
    }
    printf("%d\n",ans);
    scanf("%d",&n);
  }
  return 0;
}

