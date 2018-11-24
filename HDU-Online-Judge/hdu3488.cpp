#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#define MN 450
#define INF (int)1e9
using namespace std;

struct edge{int from,to,c,f,cost;};
vector<edge> es;
vector<int> g[MN];
int S,T;
int flow,cost;
int dis[MN];
bool ins[MN],vis[MN];

void addedge(int from,int to,int c,int cost)
{
  edge x;
  x.from=from;x.to=to;x.c=c;x.f=0;x.cost=cost;
  es.push_back(x);
  x.from=to;x.to=from;x.c=0;x.cost=-cost;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

void prepare()
{
  memset(ins,0,sizeof(ins));
  for (int i=S;i<=T;i++)
    dis[i]=INF;
  queue<int> q;
  q.push(T);
  ins[T]=true;
  dis[T]=0;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    ins[u]=false;
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (es[g[u][i]^1].c>es[g[u][i]^1].f&&dis[e.to]>dis[u]+es[g[u][i]^1].cost)
      {
        dis[e.to]=dis[u]+es[g[u][i]^1].cost;
        if (!ins[e.to])
        {
          ins[e.to]=true;
          q.push(e.to);
        }
      }
    }
  }
}

int aug(int u,int a)
{
  if (a==0) return 0;
  if (u==T)
  {
    flow+=a;
    cost+=a*dis[S];
    return a;
  }
  int ff=0,f;
  vis[u]=true;
  for (int i=0;i<g[u].size();i++)
  {
    edge e=es[g[u][i]];
    if (!vis[e.to]&&e.c>e.f&&dis[u]==dis[e.to]+e.cost)
    {
      f=aug(e.to,min(a,e.c-e.f));
      ff+=f;
      a-=f;
      es[g[u][i]].f+=f;
      es[g[u][i]^1].f-=f;
      if (a==0)
        return ff;
    }
  }
  return ff;
}

bool relabel()
{
  int t=INF;
  for (int i=S;i<=T;i++)
    if (vis[i])
      for (int j=0;j<g[i].size();j++)
      {
        edge e=es[g[i][j]];
        if (e.c>e.f&&!vis[e.to])
          t=min(t,dis[e.to]+e.cost-dis[i]);
      }
  if (t==INF) return false;
  for (int i=0;i<=T;i++)
    if (vis[i])
      dis[i]+=t;
  return true;
}

int main()
{
  freopen("3488.in","r",stdin);
  freopen("3488.out","w",stdout);
  int ca,n,i,j,k,m,v,u,w;
  scanf("%d",&ca);
  while(ca--)
  {
    es.clear();
    for (i=0;i<MN;i++)
      g[i].clear();
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      addedge(u,v+n,1,w);
    }
    for (i=1;i<=n;i++)
      addedge(0,i,1,0);
    for (i=1;i<=n;i++)
      addedge(i+n,n+n+1,1,0);
    S=0;T=n+1+n;
    memset(dis,0,sizeof(dis));
    prepare();
    cost=0;flow=0;
    do
      do memset(vis,0,sizeof(vis));
      while(aug(S,INF));
    while(relabel());
    printf("%d\n",cost);
  }
  return 0;
}
