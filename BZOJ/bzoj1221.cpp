#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define MN 2019
#define INF (int)1e9
using namespace std;

int ne[1005];
int cost,S,T;
int ans=0;
vector<int> g[MN];
struct edge{
	int from,to,c,f,cost;
};
vector<edge> es;
int dis[MN];
bool vis[MN];
bool ins[MN];
int p[MN],a[MN];

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
  ins[T]=true;
  for (int i=0;i<=T;i++)
    dis[i]=INF;
  dis[T]=0;
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
          q.push(e.to);
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
        if (e.c>e.f&&!vis[e.to])
          t=min(t,dis[e.to]+e.cost-dis[i]);
	  }
  if (t==INF)
    return false;
  for (int i=0;i<=T;i++)
    if (vis[i])
      dis[i]+=t;
  return true;
}

bool spfa()
{
  memset(ins,0,sizeof(ins));
  for (int i=0;i<=T;i++)
    dis[i]=INF;
  dis[S]=0;
  ins[S]=true;
  a[S]=INF;
  p[S]=0;
  queue<int> q;
  q.push(S);
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
          ins[e.to]=true;
          q.push(e.to);
		}
	  }
	}
  }
  if (dis[T]==INF)
    return false;
  cost+=dis[T]*a[T];
  ans+=a[T];
  int u=T;
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
  freopen("1221.in","r",stdin);
  freopen("1221.out","w",stdout);
  int a,b,f,fa,fb,n,i,j,k,m;
  scanf("%d%d%d%d%d%d",&n,&a,&b,&f,&fa,&fb);
  for (i=1;i<=n;i++)
    scanf("%d",&ne[i]);
  S=0;T=n+n+1;
  for (i=1;i<=n;i++)
  {
    addedge(S,i,ne[i],f);
    addedge(S,i+n,ne[i],0);
    if (i+a+1<=n)
      addedge(i+n,i+a+1,INF,fa);
    if (i+b+1<=n)
      addedge(i+n,i+b+1,INF,fb);
    if (i+1<=n)
      addedge(i+n,i+n+1,INF,0);
    addedge(i,T,ne[i],0);
  }
  cost=0;
  //prepare();
  do
    do memset(vis,0,sizeof(vis));
    while(aug(S,INF));
  while(relabel());
  //while(spfa());
  printf("%d\n",cost);
  return 0;
}
