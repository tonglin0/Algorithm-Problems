#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
#define INF (int)2e9
using namespace std;

//queue<int> q;
vector<int> g[204];
struct edge{int from,to,c,f;};
vector<edge> es;
int n;
int dis[204],cur[204];
bool vis[204];

void addedge(int u,int v,int w)
{
  es.push_back((edge){u,v,w,0});
  es.push_back((edge){v,u,0,0});
  int m=es.size();
  g[u].push_back(m-2);
  g[v].push_back(m-1);
}
bool bfs()
{
  memset(dis,0,sizeof(dis));
  memset(vis,0,sizeof(vis));
  queue<int> q;
  q.push(0);
  vis[0]=true;
  while(!q.empty())
  {
    int u=q.front();
    q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e;
      e=es[g[u][i]];
      if (!vis[e.to]&&e.c>e.f)
      {
        vis[e.to]=true;
        dis[e.to]=dis[u]+1;
        q.push(e.to);
      }
    }
  }
  return vis[n+n+1];
}
int dfs(int x,int a)
{
  if (x==n+n+1||a==0) return a;
  int flow=0,f;
  for (int i=0;i<g[x].size();i++)
  {
    edge& e=es[g[x][i]];
    cur[x]=i;
    if (dis[x]+1==dis[e.to]&&(f=dfs(e.to,min(a,e.c-e.f)))>0)
    {
      flow+=f;
      e.f+=f;
      a-=f;
      es[g[x][i]^1].f-=f;
      if (a==0) break;
    }
  }
  return flow;
}
int main()
{
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  int m,i,j,u,v,w;
  while(scanf("%d",&n)==1)
  {
    es.clear();
    for (i=0;i<=2*n+1;i++)
      g[i].clear();
    for (i=1;i<=n;i++)
    {
      scanf("%d",&w);
      addedge(i,i+n,w);
    }
    scanf("%d",&m);
    for (i=1;i<=m;i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      addedge(u+n,v,w);
    }
    int d,b;
    scanf("%d%d",&b,&d);
    for (i=1;i<=b;i++)
    {
      scanf("%d",&v);
      addedge(0,v,INF);
    }
    for (i=1;i<=d;i++)
    {
      scanf("%d",&v);
      addedge(v+n,2*n+1,INF);
    }
    int ans=0;
    while(bfs())
    {
      memset(cur,0,sizeof(cur));
      ans+=dfs(0,INF);
    }
    printf("%d\n",ans);
  }
}
