#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#define MN 305
using namespace std;

bool  vis[MN];
int p[MN];
vector<int> g[MN];

bool find(int u)
{
  for (int i=0;i<g[u].size();i++)
  {
    if (!vis[g[u][i]])
    {
    vis[g[u][i]]=true;
    if (p[g[u][i]]==0||find(p[g[u][i]]))
    {
      p[g[u][i]]=u;
      return true;
    }
    }
  }
  return false;
}

int main()
{
  //freopen("2239.in","r",stdin);
  //freopen("2239.out","w",stdout);
  memset(p,0,sizeof(p));
  for (int i=0;i<MN;i++) g[i].clear();
  int n,i,j,k,m,N=84;
  while(scanf("%d",&n)==1)
{
memset(p,0,sizeof(p));
  for (int i=0;i<MN;i++) g[i].clear();
  
  for (i=1;i<=n;i++)
  {
    scanf("%d",&m);
    for (j=1;j<=m;j++)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      g[i].push_back((a-1)*12+b);
    }
  }
  int ans=0;
  for (i=1;i<=n;i++)
  {
    memset(vis,0,sizeof(vis));
    if (find(i)) ans++;
  }
  printf("%d\n",ans);
}
  return 0;
}
