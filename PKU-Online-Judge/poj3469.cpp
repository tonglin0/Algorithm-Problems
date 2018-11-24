#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
#define MN 20005
#define INF (int)1e9
using namespace std;

int dis[MN],cur[MN];
bool vis[MN];
struct edge{int from,to,c,f;};
vector<edge> es;
vector<int> g[MN];
int T;

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
  memset(dis,0,sizeof(dis));
  queue<int> q;
  q.push(0);
  vis[0]=true;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&!vis[e.to])
      {
        dis[e.to]=dis[u]+1;
        vis[e.to]=true;
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
  for (int i=0;i<g[u].size();i++)
  {
    edge& e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(e.c-e.f,a)))>0)
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
  //freopen("3469.in","r",stdin);
  //freopen("3469.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&m);
  T=n+1;
  es.clear();
  for (i=0;i<MN;i++) g[i].clear();
  for (i=1;i<=n;i++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    addedge(0,i,u);
    addedge(i,T,v);
  }
  for (i=1;i<=m;i++)
  {
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    addedge(u,v,w);
    addedge(v,u,w);
  }
  int ans=0;
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans+=dfs(0,INF);
  }
  printf("%d\n",ans);
  return 0;
}
