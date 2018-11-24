#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#define INF (int)1e9
using namespace std;

int into[1209];
int cost;
struct edge{
	int from,to,c,f,cost;
};
vector<edge> es;
vector<int> g[1205];
bool vis[1205],ins[1205];
int dis[1205];
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

void prepare()
{
  memset(ins,0,sizeof(ins));
  for (int i=0;i<=T;i++)
    dis[i]=INF;
  dis[T]=0;
  queue<int> q;
  q.push(T);
  ins[T]=true;
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

int aug(int u,int a)
{
  if (u==T)
  {
    cost+=dis[S]*a;
    return a;
  }
  int flow=0,f;
  vis[u]=true;
  for (int i=0;i<g[u].size();i++)
  {
    edge e=es[g[u][i]];
    if (!vis[e.to]&&dis[u]==dis[e.to]+e.cost&&e.c>e.f)
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
  freopen("1061.in","r",stdin);
  freopen("1061.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&m);
  memset(into,0,sizeof(into));
  for (i=1;i<=n;i++)
  {
    int d;
    scanf("%d",&d);
    into[i]-=d;
    into[i+1]+=d;
    addedge(i,i+1,INF,0);
  }
  for (i=1;i<=m;i++)
  {
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    addedge(v+1,u,INF,w);
  }
  S=0;
  T=n+2;
  for (i=1;i<=n+1;i++)
    if (into[i]>0)
      addedge(S,i,into[i],0);
    else if (into[i]<0)
      addedge(i,T,-into[i],0);
  cost=0;
  prepare();
  do
    do memset(vis,0,sizeof(vis));
    while(aug(S,INF));
  while(relabel());
  printf("%d\n",cost);
  return 0;
}
