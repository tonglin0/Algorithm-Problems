#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#define MN 250
#define INF (int)1e9
using namespace std;

struct edge{int from,to,c,f,cost;};
vector<edge> es;
vector<int> g[MN];
int a[MN],p[MN],dis[MN];
bool ins[MN];
int S,T;
int cost,flow;

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

bool spfa()
{
  queue<int> q;
  q.push(S);
  memset(ins,0,sizeof(ins));
  for (int i=0;i<MN;i++)
    dis[i]=INF;
  memset(a,0,sizeof(a));
  p[S]=0;dis[S]=0;a[S]=INF;ins[S]=true;
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
        a[e.to]=min(e.c-e.f,a[u]);
        p[e.to]=g[u][i];
        if (!ins[e.to])
        {
          q.push(e.to);
          ins[e.to]=true;
        }
      }
    }
  }
  if (dis[T]==INF) return false;
  int u=T;
  flow+=a[T];
  cost+=a[T]*dis[T];
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
  freopen("1853.in","r",stdin);
  freopen("1853.out","w",stdout);
  int n,i,j,k,m,u,v,w;
  while(scanf("%d%d",&n,&m)==2)
  {
    es.clear();
    for (i=0;i<MN;i++)
      g[i].clear();
    while(m--)
    {
      scanf("%d%d%d",&u,&v,&w);
      addedge(u,v+n,1,w);
    }
    flow=0;cost=0;
    S=0;T=n+n+1;
    //for (i=1;i<=n;i++)
      //addedge(i,i+n,1,0);
    for (i=1;i<=n;i++)
      addedge(S,i,1,0);
    for (i=1;i<=n;i++)
      addedge(i+n,T,1,0);
    while(spfa());
    if (flow==n)
      printf("%d\n",cost);
    else
      printf("-1\n");
  }
  return 0;
}
