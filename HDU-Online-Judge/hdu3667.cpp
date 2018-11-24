#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#define MN 120
#define INF (int)1e9
using namespace std;

struct edge{int from,to,c,f,cost;};
vector<edge> es;
vector<int> g[MN];
int S,T;
int flow,cost;
int a[MN],p[MN],dis[MN];
bool vis[MN];
bool ins[MN];

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
  dis[T]=0;
  ins[T]=true;
  queue<int> q;
  q.push(T);
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
  if (u==T)
  {
    flow+=a;
    cost+=dis[S]*a;
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
        if (!vis[e.to]&&e.c>e.f)
          t=min(t,dis[e.to]+e.cost-dis[i]);
      }
  if (t==INF) return false;
  for (int i=S;i<=T;i++)
    if (vis[i])
      dis[i]+=t;
  return true;
}

bool spfa()
{
  queue<int> q;
  q.push(S);
  memset(ins,0,sizeof(ins));
  memset(a,0,sizeof(a));
  for (int i=0;i<=T;i++)
    dis[i]=INF;
  ins[S]=true;
  dis[S]=0;
  a[S]=INF;
  memset(p,0,sizeof(p));
  while(!q.empty())
  {
    int u=q.front();q.pop();
    ins[u]=false;
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&dis[e.to]>dis[u]+e.cost)
      {
        dis[e.to]=dis[u]+e.cost;
        p[e.to]=g[u][i];
        a[e.to]=min(a[u],e.c-e.f);
        if (!ins[e.to])
        {
          ins[e.to]=true;
          q.push(e.to);
        }
      }
    }
  }
  if (dis[T]==INF) return false;
  int u=T;
  cost+=a[T]*dis[T];
  flow+=a[T];
  while(u!=S)
  {
    es[p[u]].f+=a[T];
    es[p[u]^1].f-=a[T];
    u=es[p[u]].from;
  }
  return true;
}

int main()
{
  freopen("3667.in","r",stdin);
  freopen("3667.out","w",stdout);
  int n,i,k,m,a,j,ask;
  while(scanf("%d%d%d",&n,&m,&ask)==3)
  {
    es.clear();
    for (i=0;i<MN;i++)
      g[i].clear();
    while(m--)
    {
      int u,v,a,c;
      scanf("%d%d%d%d",&u,&v,&a,&c);
      for (i=1;i<=c;i++)
        addedge(u,v,1,(2*i-1)*a);
    }
    S=0;T=n+1;
    addedge(0,1,ask,0);
    addedge(n,T,ask,0);
    flow=0;cost=0;
    prepare();
    do 
      do
        memset(vis,0,sizeof(vis));
      while(aug(S,INF));
    while(relabel());
    //while(spfa());
    if (flow==ask)
      printf("%d\n",cost);
    else
      printf("-1\n");
  }
  return 0;
}
