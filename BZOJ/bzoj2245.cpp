#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<ctime>
#include<queue>
#include<string>
#include<vector>
#include<map>
#define eps 1e-8
#define INF (int)1e9
#define lint long long
#define MN 509
#define llu unsigned long long
using namespace std;

int tmp[MN];
struct edge{
	int from,to,c,f,cost;
};
lint flow=0,cost=0;
vector<edge> es;
vector<int> g[MN];
int dis[MN];
int S,T;
int p[MN],a[MN];
bool vis[MN],ins[MN];

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
  for (int i=0;i<=T;i++)
    dis[i]=INF;
  dis[T]=0;
  for (int i=0;i<=T;i++)
    ins[i]=false;
  queue<int> q;
  q.push(T);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    ins[u]=false;
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (es[g[u][i]^1].c>es[g[u][i]^1].f&&dis[u]+es[g[u][i]^1].cost<dis[e.to])
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


bool spfa()
{
  for (int i=0;i<=T;i++)
    dis[i]=INF;
  memset(ins,0,sizeof(ins));
  queue<int> q;
  q.push(S);
  p[S]=0;
  dis[S]=0;
  a[S]=INF;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    ins[u]=false;
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&dis[u]+e.cost<dis[e.to])
      {
        dis[e.to]=dis[u]+e.cost;
        p[e.to]=g[u][i];
        a[e.to]=min(a[u],e.c-e.f);
        if (!ins[e.to])
        {
          q.push(e.to);
          ins[e.to]=true;
		}
	  }
	}
  }
  if (dis[T]==INF)
    return false;
  int u=T;
  //flow+=a[T];
  cost+=(lint)dis[T]*a[T];
  while(u!=S)
  {
    es[p[u]].f+=a[T];
    es[p[u]^1].f-=a[T];
    u=es[p[u]].from;
  }
  return true;
}


int aug(int u,int a)
{
  if (u==T||a==0)
  {
    cost+=dis[S]*a;
    return a;
  }
  vis[u]=true;
  int flow=0,f;
  for (int i=0;i<g[u].size();i++)
  {
    edge e=es[g[u][i]];
    if (e.c>e.f&&!vis[e.to]&&dis[u]==dis[e.to]+e.cost)
    {
      f=aug(e.to,min(e.c-e.f,a));
      flow+=f;
      a-=f;
      es[g[u][i]].f+=f;
      es[g[u][i]^1].f-=f;
      if (a==0)
        return flow;
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
          t=min(t,dis[e.to]+e.cost-dis[i]);
	  }
  if (t==INF)
    return false;
  for (int i=0;i<=T;i++)
    if (vis[i])
      dis[i]+=t;
  return true;
}

int main()
{
  freopen("2245.in","r",stdin);
  freopen("2245.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  scanf("%d%d",&m,&n);
  S=0;T=n+m+1;
  for (i=1;i<=n;i++)
  {
    int d;
    scanf("%d",&d);
    addedge(i+m,T,d,0);
  }
  for (i=1;i<=m;i++)
    for (j=1;j<=n;j++)
    {
      int d;
      scanf("%d",&d);
      if (d==1)
        addedge(i,j+m,INF,0);
	}
  for (i=1;i<=m;i++)
  {
    int si;
    scanf("%d",&si);
    tmp[0]=0;tmp[si+1]=INF;
    for (j=1;j<=si;j++)
      scanf("%d",&tmp[j]);
    for (j=1;j<=si+1;j++)
    {
      int w;
      scanf("%d",&w);
      addedge(S,i,tmp[j]-tmp[j-1],w);
	}
  }
  prepare();
  do
    do memset(vis,0,sizeof(vis));
    while(aug(S,INF));
  while(relabel());
  //while(spfa());
  printf("%lld\n",cost);
  return 0;
}

