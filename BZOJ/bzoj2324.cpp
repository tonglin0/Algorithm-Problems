#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#define INF (int)1e9
#define MN 155
using namespace std;

int map[MN][MN];
struct edge{int from,to,c,f,cost;};
vector<edge> es;
vector<int> g[405];
int dis[MN][MN][MN];
int cost;
int a[405],pre[405],d[405];
bool ins[405];
int T,S;
bool vis[405];

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
/*
bool spfa()
{
  queue<int> q;
  q.push(S);
  for (int i=0;i<405;i++)
    d[i]=INF;
  d[S]=0;
  memset(ins,0,sizeof(ins));
  ins[S]=true;
  a[S]=INF;
  pre[S]=0;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    ins[u]=false;
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&d[u]+e.cost<d[e.to])
      {
        d[e.to]=d[u]+e.cost;
        pre[e.to]=g[u][i];
        a[e.to]=min(e.c-e.f,a[u]);
        if (!ins[e.to])
        {
          ins[e.to]=true;
          q.push(e.to);
        }
      }
    }
  }
  if (d[T]==INF) return false;
  cost+=a[T]*d[T];
  flow+=a[T];
  int u=T;
  while(u!=S)
  {
    es[pre[u]].f+=a[T];
    es[pre[u]^1].f-=a[T];
    u=es[pre[u]].from;
  }
  return true;
}*/


void prepare()
{
  queue<int> q;
  q.push(T);
  for (int i=0;i<=T;i++)
    d[i]=INF;
   d[T]=0;
  memset(ins,0,sizeof(ins));
  while(!q.empty())
  {
    int u=q.front();q.pop();
    ins[u]=false;
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (es[g[u][i]^1].c>es[g[u][i]^1].f&&d[u]+es[g[u][i]^1].cost<d[e.to])
      {
        d[e.to]=d[u]+es[g[u][i]^1].cost;
        if(!ins[e.to])
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
    cost+=a*d[S];
    return a;
  }
  vis[u]=true;
  int flow=0,f;
  for(int i=0;i<g[u].size();i++)
  {
    edge e=es[g[u][i]];
    if (e.c>e.f&&!vis[e.to]&&d[u]==d[e.to]+e.cost)
    {
      f=aug(e.to,min(a,e.c-e.f));
      flow+=f;
      a-=f;
      es[g[u][i]].f+=f;
      es[g[u][i]^1].f-=f;
      if(a==0) return flow;
    }
  } 
  return flow;
}

bool relabel()
{
  int t=INF;
  for (int i=0;i<=T;i++)
    if (vis[i])
      for (int j=0;j<g[i].size();j++)
      {
        edge e=es[g[i][j]];
        if (!vis[e.to]&&e.c>e.f)
          t=min(t,d[e.to]+e.cost-d[i]);
      }
  if (t==INF) return false;
  for (int i=0;i<=T;i++)
    if (vis[i])
      d[i]+=t;
  return true;
}

int main()
{
  freopen("2324.in","r",stdin);
  freopen("2324.out","w",stdout);
  int n,i,j,k,m,u,v,w,p;
  scanf("%d%d%d",&n,&m,&p);
  for (i=0;i<=n;i++)
    for (j=0;j<=n;j++)
      map[i][j]=INF;
  for (i=1;i<=m;i++)
  {
    scanf("%d%d%d",&u,&v,&w);
    if (w<map[u][v])
      map[u][v]=map[v][u]=w;
  }
  for (k=0;k<=n;k++)
  {
    for (i=0;i<=n;i++)
      for (j=0;j<=n;j++)
        map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
    for (i=0;i<=n;i++)
      for (j=0;j<=n;j++)
        dis[k][i][j]=map[i][j];
  }
  S=n+n+2;T=n+n+3;
  addedge(S,0,p,0);
  for (i=0;i<=n;i++)
    addedge(i,i+n+1,INF,0);
  for (i=0;i<=n;i++)
    addedge(i,T,1,0);
  for (i=0;i<=n;i++)
    for (j=i+1;j<=n;j++)
      if (dis[j][i][j]<INF)
        addedge(i+n+1,j,INF,dis[j][i][j]);
  for (i=0;i<=n;i++)
    addedge(S,i+n+1,1,0);
  cost=0;
  //while(spfa());
  prepare();
  do
    do memset(vis,0,sizeof(vis));
    while(aug(S,INF));
  while(relabel());
  printf("%d\n",cost);
  return 0;
}
