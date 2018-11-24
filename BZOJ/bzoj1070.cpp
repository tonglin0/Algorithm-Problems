#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define INF (int)1e9
#define MN 1003
using namespace std;

struct edge{int from,to,c,f,cost;};
vector<edge> es;
vector<int> g[MN];
bool vis[MN];
int tim[65][12];
int dis[MN];
int cost=0;
int S,T;

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

int aug(int u,int a)
{
  if (u==T)//if (u==T)
  {
    cost+=a*dis[S];
    return a;
  }
  vis[u]=true;
  int A=a;
  for (int i=0;i<g[u].size();i++)
  {
    edge e=es[g[u][i]];
    if (e.c>e.f&&!vis[e.to]&&dis[u]==dis[e.to]+e.cost)
    {
      int f=aug(e.to,min(e.c-e.f,A));
      es[g[u][i]].f+=f;
      es[g[u][i]^1].f-=f;
      A-=f;
      if (A==0) return a;
    }
  }
  return a-A;
}

int p[MN],a[MN];
bool ins[MN];
bool spfa()
{
  memset(dis,60,sizeof(dis));
  memset(ins,0,sizeof(ins));
  memset(a,0,sizeof(a));
  memset(p,0,sizeof(p));
  dis[0]=0;
  a[0]=INF;
  ins[0]=true;
  queue<int> q;
  q.push(0);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    ins[u]=false;
    for(int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&dis[e.to]>dis[u]+e.cost)
      {
        dis[e.to]=dis[u]+e.cost;
        a[e.to]=min(a[u],e.c-e.f);
        p[e.to]=g[u][i];
        if (!ins[e.to])
        {
          ins[e.to]=true;
          q.push(e.to);
        }
      }
    }
  }
  if (dis[7]==dis[MN-2]) return false;
  cost+=dis[7]*a[7];
  int u=7;
  while(u!=0)
  {
    es[p[u]].f+=a[7];
    es[p[u]^1].f-=a[7];
    u=es[p[u]].from;
  }
  return true;
}

bool modlabel()
{
  int t=INF;
  for(int i=0;i<=T;i++)
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
  //freopen("1070.in","r",stdin);
  //freopen("1070.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&m,&n);
  memset(tim,0,sizeof(tim));
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      scanf("%d",&tim[i][j]);
  S=0,T=n+m*n+1;
  for (i=1;i<=n;i++)
    addedge(S,i,1,0);
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      for (k=1;k<=n;k++)
        addedge(i,(j-1)*n+n+k,1,tim[i][j]*k);
  for (j=1;j<=m;j++)
    for (k=1;k<=n;k++)
      addedge((j-1)*n+n+k,T,1,0);
  memset(dis,0,sizeof(dis));
  /*for (i=0;i<g[S].size();i++)
  {
    edge e=es[g[S][i]];
    if (e.c>e.f)
      printf("%d ",e.to);
  }
  return 0;*/
  do
    do memset(vis,0,sizeof(vis));
    while(aug(S,INF));
  while(modlabel());
  //while(spfa());
  printf("%.2lf\n",1.0*cost/n);
  return 0;
}
