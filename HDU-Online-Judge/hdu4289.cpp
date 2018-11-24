#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
#define INF (int)1e9
#define MN 450
using namespace std;

struct edge{int from,to,c,f;};
vector<edge> es;
vector<int> g[MN];
int dis[MN],cur[MN];
bool vis[MN];
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
  queue<int> q;
  memset(vis,0,sizeof(vis));
  memset(dis,0,sizeof(dis));
  q.push(S);
  vis[S]=true;
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
  int flow=0,f;
  if (u==T||a==0) return a;
  for (int i=cur[u];i<g[u].size();i++)
  {
    cur[u]=i;
    edge& e=es[g[u][i]];
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
  freopen("4289.in","r",stdin);
  freopen("4289.out","w",stdout);
  int n,i,j,k,m,d;
  while(scanf("%d%d",&n,&m)==2)
  {
    scanf("%d%d",&S,&T);
    T+=n;
    es.clear();
    for (i=0;i<MN;i++)
      g[i].clear();
    for (i=1;i<=n;i++)
    {
      scanf("%d",&d);
      addedge(i,i+n,d);
    }
    for (i=1;i<=m;i++)
    {
      int u,v;
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
