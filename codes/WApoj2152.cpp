#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define INF (int)1e9
using namespace std;

struct node{
       int v,w;
};
vector<node> g[1004];
int dep[1004];
int dis[1004][1004];
bool can[1004][1004];
int ans;
int f[1004][1004];
int d[1004],w[1004];
bool vis[1004][1004];

void dfs(int u,int pre,int d)
{
  dep[u]=dep[pre]+d;
  for (int i=0;i<g[u].size();i++)
    if (g[u][i].v!=pre)
      dfs(g[u][i].v,u,g[u][i].w);
}

int work(int u,int ne,int pre)
{
  if (vis[u][ne])
    return f[u][ne];
  vis[u][ne]=true;
  int t=0;
  if (can[u][ne])
  {
    int t1=w[u],t2=0;
    bool flag=false;
    for (int i=0;i<g[u].size();i++)
      if (g[u][i].v!=pre)
      {
        t1+=work(g[u][i].v,u,u);
        t2+=work(g[u][i].v,ne,u);
        flag=true;
      }
    if (!flag)
      return f[u][ne]=0;
    t=min(t1,t2);
  }
  else
  {
    bool flag=false;
    t=w[u];
    for (int i=0;i<g[u].size();i++)
      if (g[u][i].v!=pre)
      {
        t+=work(g[u][i].v,u,u);
        flag=true;
      }
    if (!flag)
      return f[u][ne]=w[u];
  }
  return f[u][ne]=t;
}

int main()
{
  freopen("2152.in","r",stdin);
  freopen("2152.out","w",stdout);
  int ca,n,i,j,k,m;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%d",&w[i]);
    for (i=1;i<=n;i++)
      scanf("%d",&d[i]);
    for (i=0;i<=n;i++)
      g[i].clear();
    for (i=1;i<n;i++)
    {
      int u,v,w;
      scanf("%d%d%d",&u,&v,&w);
      node tmp;
      tmp.v=v;tmp.w=w;
      g[u].push_back(tmp);
      tmp.v=u;
      g[v].push_back(tmp);
    }
    for (i=1;i<=n;i++)
    {
      dep[i]=0;
      for (int ii=0;ii<g[i].size();ii++)
        dfs(g[i][ii].v,i,g[i][ii].w);
      for (j=1;j<=n;j++)
        dis[i][j]=dep[j];
    }
    memset(can,0,sizeof(can));
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        if (dis[i][j]<=d[i])
          can[i][j]=true;
    ans=INF;
    memset(vis,0,sizeof(vis));
    for (i=1;i<=n;i++)
    {
      //memset(vis,0,sizeof(vis));
      int s=0;
      for (j=0;j<g[i].size();j++)
        s+=work(g[i][j].v,i,i);
      ans=min(ans,s+w[i]);
    }
    printf("%d\n",ans);
  }
  return 0;
}
