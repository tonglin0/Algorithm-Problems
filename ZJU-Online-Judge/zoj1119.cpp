#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#define MN 2003
using namespace std;

int pre[MN],child[MN],low[MN];
int dfsclock=0;
vector<int> g[MN];
bool iscut[MN];
bool vis[MN];

int dfs(int u,int fa)
{
  int lowu=pre[u]=++dfsclock;
  for (int i=0;i<g[u].size();i++)
  {
    int v=g[u][i];
    if (!pre[v])
    {
      int lowv=dfs(v,u);
      lowu=min(lowu,lowv);
      if (lowv>=pre[u])
      { 
        iscut[u]=true;
        ++child[u];
      }
    }
    else if (pre[v]<pre[u]&&v!=fa)
      lowu=min(pre[v],lowu);
  }
  if (fa==-1&&child[u]==1) iscut[u]=false;
  low[u]=lowu;
  if (fa>0)child[u]++;
  return lowu;
}

int main()
{
  freopen("1119.in","r",stdin);
  freopen("1119.out","w",stdout);
  int n,i,j,k,ii=0,m,d,v,u;
  scanf("%d",&d);
  bool flag=true;
  while(d)
  {
    u=d;
    if (!flag) printf("\n");
    flag=false;
    ii++;
    memset(vis,0,sizeof(vis));
    for (i=0;i<=MN;i++)
      g[i].clear();
    memset(pre,0,sizeof(pre));
    memset(child,0,sizeof(child));
    memset(low,0,sizeof(low));
    dfsclock=0;    
    while(u)
    {
      scanf("%d",&v);
      g[u].push_back(v);
      g[v].push_back(u);
      vis[u]=true;
      vis[v]=true;
      scanf("%d",&u);
    }
    memset(iscut,0,sizeof(iscut));
    for (i=1;i<=1000;i++)
      if (vis[i])
      {
        dfs(i,-1);
        break;
      }
    int ans=0;
    for (i=1;i<=1000;i++)
      if (iscut[i])
        ans++;
    printf("Network #%d\n",ii);
    if (ans==0)
      printf("  No SPF nodes\n");
    else
    {
      for (i=1;i<=1000;i++)
        if (iscut[i])
        printf("  SPF node %d leaves %d subnets\n",i,child[i]);
    }
    //printf("\n");
    scanf("%d",&d);
  }
  return 0;
}
