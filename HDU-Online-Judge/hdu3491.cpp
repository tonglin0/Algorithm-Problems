#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#define MN 250
#define INF (int)1e9
using namespace std;

struct edge{int from,to,c,f;};
vector<edge> es;
vector<int> g[MN];
bool vis[MN];
int dis[MN],cur[MN];
int S,T;

void addedge(int from,int to,int c)
{
  edge x;
  x.from=from;x.to=to;x.c=c;x.f=0;
  es.push_back(x);
  x.from=to;x.to=from;x.c=0;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

bool bfs()
{
  memset(vis,0,sizeof(vis));
  dis[S]=0;
  vis[S]=true;
  queue<int> q;
  q.push(S);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (!vis[e.to]&&e.c>e.f)
      {
        vis[e.to]=true;
        dis[e.to]=dis[u]+1;
        q.push(e.to);
      }
    }
  }
  return vis[T];
}

int dfs(int u,int a)
{
  if (u==T||a==0) return a;
  int flow=0,f;
  for (int i=cur[u];i<g[u].size();i++)
  {
    cur[u]=i;
    edge &e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(a,e.c-e.f)))>0)
    {
      flow+=f;
      a-=f;
      e.f+=f;
      es[g[u][i]^1].f-=f;
      if (a==0) return flow;
    }
  }
  return flow;
}

int main()
{
  freopen("3491.in","r",stdin);
  freopen("3491.out","w",stdout);
  int n,i,j,k,m,d,u,v,ca;
  scanf("%d",&ca);
  while(ca--)
  {
    for (i=0;i<MN;i++)
      g[i].clear();
    es.clear();
    scanf("%d%d%d%d",&n,&m,&S,&T);
    for (i=1;i<=n;i++)
    {
      scanf("%d",&d);
      if (i==S||i==T)
        addedge(i,i+n,INF);
      else
        addedge(i,i+n,d);
    }
    while(m--)
    {
      scanf("%d%d",&u,&v);
      addedge(u+n,v,INF);
      addedge(v+n,u,INF);
    }
    int ans=0;
    while(bfs())
    {
      memset(cur,0,sizeof(cur));
      ans+=dfs(S,INF);
    }
    printf("%d\n",ans);
  }
  return 0;
}
